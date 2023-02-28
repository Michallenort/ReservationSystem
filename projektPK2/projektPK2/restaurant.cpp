#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

restaurant::restaurant(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour)
{
    for (auto i : tables)
    {
        this->tables.push_back(i);
    }

    this->openHour = openHour;
    this->closeHour = closeHour;
}

restaurant::restaurant(std::pair<int, int> openHour, std::pair<int, int> closeHour)
{
    this->openHour = openHour;
    this->closeHour = closeHour;
}

void restaurant::setTables(std::vector<table> tables)
{
    for (auto i : tables)
    {
        this->tables.push_back(i);
    }
}
void restaurant::setOpenHour(int first, int second)
{
    this->openHour.first = first;
    this->openHour.second = second;
}
void restaurant::setCloseHour(int first, int second)
{
    this->closeHour.first = first;
    this->closeHour.second = second;
}

std::vector<table> restaurant::getTables() const { return this->tables; }
std::pair<int, int> restaurant::getOpenHour() const { return this->openHour; }
std::pair<int, int> restaurant::getCloseHour() const { return this->closeHour; }

void restaurant::reserveTable()
{
    std::pair<int, int> startHour, endHour;
    int year, month, day;

    do
    {
        std::cout << "Podaj date\nRok: ";
        std::cin >> year;
        std::cout << "Miesiac: ";
        std::cin >> month;
        std::cout << "Dzien: ";
        std::cin >> day;

        if (!isDateCorrect(year, month, day))
        {
            std::cout << "Niepoprawna data! Sproboj jeszcze raz" << std::endl;
        }

    } while (!isDateCorrect(year, month, day));

    do
    {
        std::cout << "Podaj godziny rezerwacji!\nRozpoczecie\nGodzina: ";
        std::cin >> startHour.first;
        std::cout << "Minuta: ";
        std::cin >> startHour.second;
        std::cout << "Koniec rezerwacji\nGodzina: ";
        std::cin >> endHour.first;
        std::cout << "Minuta: ";
        std::cin >> endHour.second;

        if (!isHourCorrect(startHour) || !isHourCorrect(endHour))
        {
            std::cout << "Niepoprawne godziny! Sproboj jeszcze raz!" << std::endl;
        }

        if (!checkHour(openHour, closeHour, startHour, endHour))
        {
            std::cout << "Restauracja w tych godzinach nie pracuje!" << std::endl;
        }
    } while (!isHourCorrect(startHour) || !isHourCorrect(endHour) || !checkHour(openHour, closeHour, startHour, endHour));

    int n;
    std::cout << "Na ile osob chcesz stolik?: ";
    std::cin >> n;

    std::vector<int> freeTables;

    for (std::size_t i = 0; i < tables.size(); i++)
    {
        if (checkTables(year, month, day, startHour, endHour, n, tables[i]))
        {
            freeTables.push_back(i + 1);
            std::cout << "Stolik nr." << i + 1 << " jest wolny w tym czasie!" << std::endl;
        }
    }

    if (freeTables.size() == 0)
    {
        std::cout << "Niestety nie ma stolikow na taka liczbe osob o tej godzinie!" << std::endl;
    }
    else
    {
        int yourChoice;
        do
        {
            std::cout << "Ktory stolik chcesz wybrac?: ";
            std::cin >> yourChoice;

            if (checkYourChoice(freeTables, yourChoice))
            {
                std::string name, secondName, telephone;

                do
                {
                    std::cout << "Podaj imie: ";
                    std::cin >> name;

                    correctName(name);

                    if (!isNameCorrect(name))
                    {
                        std::cout << "Niepoprawne imie! Sproboj jeszcze raz!" << std::endl;
                    }
                } while (!isNameCorrect(name));

                do
                {
                    std::cout << "Nazwisko: ";
                    std::cin >> secondName;

                    correctName(secondName);

                    if (!isNameCorrect(secondName))
                    {
                        std::cout << "Niepoprawne nazwisko! Sproboj jeszcze raz!" << std::endl;
                    }
                } while (!isNameCorrect(secondName));

                do
                {
                    std::cout << "Numer telefonu:";
                    std::cin >> telephone;

                    if (!isTelephoneCorrect(telephone))
                    {
                        std::cout << "Niepoprawny numer telefonu! Sproboj jeszcze raz!" << std::endl;
                    }
                } while (!isTelephoneCorrect(telephone));


                customer newCustomer(name, secondName, telephone);

                reservation newReservation(newCustomer, startHour, endHour, day, month, year);

                tables[yourChoice - 1].reservations.push_back(newReservation);

                std::cout << "Udalo sie pomyslnie zarezerwowac stolik!" << std::endl;
            }
            else
            {
                std::cout << "Wybrales zly stolik, sprobuj jeszcze raz!" << std::endl;
            }

        } while (!checkYourChoice(freeTables, yourChoice));
    }

}

bool restaurant::checkTables(int year, int month, int day, std::pair<int, int> startHour, std::pair<int, int> endHour, int n, table t)
{
    std::vector<reservation> reservations = t.getReservations();

    if (n == t.getCustomersNumber())
    {
        for (std::size_t i = 0; i < reservations.size(); i++)
        {
            if (year == reservations[i].getYear() && month == reservations[i].getMonth() && year == reservations[i].getYear())
                if (!checkReservationHour(reservations[i].getStartHour(), reservations[i].getEndHour(), startHour, endHour))
                {
                    return false;
                }
        }
        return true;
    }
    else
        return false;
}

void restaurant::cancelReservation()
{
    std::string name, secondName, telephone;
    int day, month, year;
    std::pair<int, int> startHour, endHour;
    bool isReservationExist = false;

    do
    {
        std::cout << "Podaj imie: ";
        std::cin >> name;

        correctName(name);

        if (!isNameCorrect(name))
        {
            std::cout << "Niepoprawne imie! Sproboj jeszcze raz!" << std::endl;
        }
    } while (!isNameCorrect(name));

    do
    {
        std::cout << "Nazwisko: ";
        std::cin >> secondName;

        correctName(secondName);

        if (!isNameCorrect(secondName))
        {
            std::cout << "Niepoprawne nazwisko! Sproboj jeszcze raz!" << std::endl;
        }
    } while (!isNameCorrect(secondName));

    do
    {
        std::cout << "Numer telefonu:";
        std::cin >> telephone;

        if (!isTelephoneCorrect(telephone))
        {
            std::cout << "Niepoprawny numer telefonu! Sproboj jeszcze raz!" << std::endl;
        }
    } while (!isTelephoneCorrect(telephone));

    do
    {
        std::cout << "Podaj date\nRok: ";
        std::cin >> year;
        std::cout << "Miesiac: ";
        std::cin >> month;
        std::cout << "Dzien: ";
        std::cin >> day;

        if (!isDateCorrect(year, month, day))
        {
            std::cout << "Niepoprawna data! Sproboj jeszcze raz" << std::endl;
        }

    } while (!isDateCorrect(year, month, day));

    for (std::size_t i = 0; i < tables.size(); i++)
    {

        for (auto iter = tables[i].reservations.begin(); iter != tables[i].reservations.end(); iter++)
        {
            customer c = iter->getClient();


            if (name == c.getName() && secondName == c.getSecondName() && telephone == c.getTelephone()
                && day == iter->getDay() && month == iter->getMonth() && year == iter->getYear())
            {
                tables[i].reservations.erase(iter);
                isReservationExist = true;
                break;
            }
        }
        if (isReservationExist == true)
            break;
    }

    if (isReservationExist == true)
        std::cout << "Twoja rezerwacja zostala usunieta!" << std::endl;
    else
        std::cout << "Nie ma takiej rezerwacji!" << std::endl;
}

void restaurant::uploadFromFile(std::string fileName)
{
    std::ifstream file(fileName);

    if (file)
    {
        std::string line;
        int lineNumber = 0;
        while (getline(file, line))
        {
            lineNumber++;

            if (line.length() != 0)
            {
                int customersNumber;
                int day, month, year;
                std::pair<int, int> startHour, endHour;
                std::string name, secondName, telephone;
                char point1, point2, char1, char2, char3;
                std::stringstream ss;

                ss << line;
                ss >> customersNumber >> day >> point1 >> month >> point2 >> year;

                ss >> startHour.first >> char1 >> startHour.second >> char2 >> endHour.first >> char3 >> endHour.second;

                ss >> name >> secondName >> telephone;

                if (!ss.fail())
                {
                    if (isDateCorrect(year, month, day) && isHourCorrect(startHour) && isHourCorrect(endHour) && isNameCorrect(name)
                        && isNameCorrect(secondName) && isTelephoneCorrect(telephone))
                    {
                        if (checkHour(openHour, closeHour, startHour, endHour))
                        {
                            bool isTableExist = false;

                            for (std::size_t i = 0; i < tables.size(); i++)
                            {
                                if (checkTables(year, month, day, startHour, endHour, customersNumber, tables[i]))
                                {
                                    isTableExist = true;

                                    correctName(name);
                                    correctName(secondName);

                                    customer newCustomer(name, secondName, telephone);

                                    reservation newReservation(newCustomer, startHour, endHour, day, month, year);

                                    tables[i].reservations.push_back(newReservation);
                                    std::cout << "Linia nr." << lineNumber << ": Dokonano pomyslnie rezerwacji na stolik nr." << i + 1 << std::endl;
                                    break;
                                }
                            }

                            if (isTableExist == false)
                            {
                                std::cout << "Linia nr." << lineNumber << ": Nie znaleziono stolika o takiej liczbie osob!" << std::endl;
                            }
                        }
                        else
                        {
                            std::cout << "Linia nr." << lineNumber << ": Restauracja w  tych godzinach nie pracuje!" << std::endl;
                        }
                    }
                    if (!isDateCorrect(year, month, day))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledna data!" << std::endl;
                    }
                    if (!isHourCorrect(startHour))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledna godzina rozpoczecia rezerwacji!" << std::endl;
                    }
                    if (!isHourCorrect(endHour))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledna godzina zakonczenia rezerwacji!" << std::endl;
                    }
                    if (!isNameCorrect(name))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledne imie!" << std::endl;
                    }
                    if (!isNameCorrect(secondName))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledne nazwisko!" << std::endl;
                    }
                    if (!isTelephoneCorrect(telephone))
                    {
                        std::cout << "Linia nr." << lineNumber << ": Bledny numer telefonu!" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Linia nr." << lineNumber << ": Dane zostaly wprowadzone w bledny sposob!" << std::endl;
                }
            }
            else
            {
                std::cout << "Linia nr." << lineNumber << " jest pusta!" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Nie znaleziono pliku!" << std::endl;
    }
    file.close();
}

void restaurant::uploadToFile(std::string fileName)
{
    std::ofstream file(fileName);

    if (file)
    {
        for (std::size_t i = 0; i < tables.size(); i++)
        {
            file << "Stolik nr." << i + 1 << ":" << std::endl;

            for (std::size_t j = 0; j < tables[i].reservations.size(); j++)
            {
                file << tables[i].reservations[j];
            }
        }
    }
    file.close();
}


void restaurant::printReservations()
{
    for (std::size_t i = 0; i < tables.size(); i++)
    {
        std::cout << "Stolik nr." << i + 1 << ":" << std::endl;

        for (std::size_t j = 0; j < tables[i].reservations.size(); j++)
        {
            std::cout << tables[i].reservations[j];
        }
    }
}