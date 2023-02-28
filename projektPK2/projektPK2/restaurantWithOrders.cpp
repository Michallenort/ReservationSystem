#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

restaurantWithOrders::restaurantWithOrders(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour, std::vector<std::pair<std::string, int>> menuCard, std::vector<order> orders)
{
    for (auto i : tables)
    {
        this->tables.push_back(i);
    }

    this->openHour = openHour;
    this->closeHour = closeHour;
    
    for (std::size_t i = 0; i < menuCard.size(); i++)
    {
        this->menuCard.push_back({ menuCard[i].first, menuCard[i].second });
    }

    for (std::size_t i = 0; i < orders.size(); i++)
    {
        this->orders.push_back(orders[i]);
    }
}

restaurantWithOrders::restaurantWithOrders(std::pair<int, int> openHour, std::pair<int, int> closeHour)
{
    this->openHour = openHour;
    this->closeHour = closeHour;
}

void restaurantWithOrders::setMenuCard(std::vector<std::pair<std::string, int>> menuCard)
{
    for (std::size_t i = 0; i < menuCard.size(); i++)
    {
        this->menuCard.push_back({ menuCard[i].first, menuCard[i].second });
    }
}
void restaurantWithOrders::setOrders(std::vector<order> orders)
{
    for (std::size_t i = 0; i < orders.size(); i++)
    {
        this->orders.push_back(orders[i]);
    }
}

std::vector<std::pair<std::string, int>> restaurantWithOrders::getMenuCard() const
{
    return this->menuCard;
}
std::vector<order> restaurantWithOrders::getOrders() const
{
    return this->orders;
}

void restaurantWithOrders::uploadMenuCard(std::string fileName)
{
    std::ifstream file(fileName);

    if (file)
    {
        std::string line;

        while (getline(file, line))
        {
            std::string dish = "";
            std::string stringPrice = "";
            int price;
            std::size_t i = 0;

            while (line[i] != '-')
            {
                dish += line[i];
                i++;
            }

            while (i < line.length())
            {
                if (isdigit(line[i]))
                    stringPrice += line[i];
                i++;
            }
            price = std::stoi(stringPrice);

            menuCard.push_back({ dish, price });
        }
    }
    else
    {
        std::cout << "Nie ma takiego pliku!" << std::endl;
    }
    file.close();
}

void restaurantWithOrders::printMenuCard()
{
    std::cout << "NASZE MENU: " << std::endl;
    for (std::size_t i = 0; i < menuCard.size(); i++)
    {
        std::cout << i + 1 << "." << menuCard[i].first << " - " << menuCard[i].second << std::endl;
    }
}

void restaurantWithOrders::addOrder()
{
    std::string name, secondName, telephone;
    order newOrder;
    printMenuCard();

    int choice;
    std::cout << "Ktore dania wybierasz?" << std::endl;
    std::cout << "Jesli chcesz zakonczyc wybierz " << menuCard.size() + 1 << std::endl;
    do
    {
        std::cin >> choice;

        if (choice > 0 && choice <= menuCard.size())
        {
            newOrder.orderDishesPushBack(menuCard[choice - 1].first, menuCard[choice - 1].second);

            std::cout << "Zamowiono: " << menuCard[choice - 1].first << std::endl;
        }
        else if (choice == menuCard.size() + 1)
        {
            std::cout << "Cena koncowa: " << newOrder.getTotalPrice() << std::endl;
            std::cout << "Dziekujemy za zlozenie zamowienia!" << std::endl;
        }
        else
        {
            std::cout << "Nie ma takiego dania!" << std::endl;
        }

    } while (choice != menuCard.size() + 1);

    if (newOrder.getTotalPrice() != 0)
    {
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

        newOrder.setName(name);
        newOrder.setSecondName(secondName);
        newOrder.setTelephone(telephone);

        orders.push_back(newOrder);
    }
}

void restaurantWithOrders::removeOrder()
{
    std::string name, secondName, telephone;
    bool isOrderExist = false;

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

    std::vector<order>::iterator iter;

    for (iter = orders.begin(); iter != orders.end(); iter++)
    {
        if (name == iter->getName() && secondName == iter->getSecondName() && telephone == iter->getTelephone())
        {
            orders.erase(iter);
            std::cout << "Pomyslnie usunieto zamowienie!" << std::endl;
            isOrderExist = true;
            break;
        }
    }

    if (isOrderExist == false)
    {
        std::cout << "Niestety nie ma takiego zamowienia!" << std::endl;
    }
}

void restaurantWithOrders::printOrders()
{
    for (std::size_t i = 0; i < orders.size(); i++)
    {
        std::cout << "Zamowienie nr." << i + 1 << ": " << std::endl;
        std::cout << orders[i];
    }
}

void restaurantWithOrders::menu()
{
    std::cout << "Witamy w naszej restauracji!\nCo masz zamiar zrobic?:" << std::endl;
    int n = 0;
    do
    {

        std::cout << "1.Zarezerwuj stolik.\n2.Odwolaj rezerwacje.\n3.Wyswietl rezerwacje.\n4.Pobierz rezerwacje z pliku.\n5.Zapisz rezerwacje w pliku." << std::endl;
        std::cout << "6.Pobierz menu z pliku.\n7.Wyswietl menu.\n8.Dokonaj zamowienia.\n9.Cofnij zamowienie.\n10.Wyswietl zamowienie.\n11.Zakoncz program." << std::endl;
        std::cout << "Co wybierasz?:";

        std::cin >> n;

        if (std::cin.fail())
        {
            std::cout << "To nie jest liczba!" << std::endl;
            break;
        }
        else
        {
            switch (n)
            {
                case 1:
                {
                    reserveTable();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 2:
                {
                    cancelReservation();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 3:
                {
                    printReservations();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 4:
                {
                    std::string fileName;
                    std::cout << "Podaj nazwe pliku: ";
                    std::cin >> fileName;

                    uploadFromFile(fileName);
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 5:
                {
                    std::string fileName;
                    std::cout << "Podaj nazwe pliku: ";
                    std::cin >> fileName;

                    uploadToFile(fileName);
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 6:
                {
                    std::string fileName;
                    std::cout << "Podaj nazwe pliku: ";
                    std::cin >> fileName;

                    uploadMenuCard(fileName);
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 7:
                {
                    printMenuCard();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 8:
                {
                    addOrder();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 9:
                {
                    removeOrder();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 10:
                {
                    printOrders();
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
                case 11:
                {
                    std::cout << "Dziekujemy i do zobaczenia ;)" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;

                    break;
                }
                default:
                {
                    std::cout << "Nie ma takiej opcji!" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "-------------------------------------" << std::endl;
                    break;
                }
            }
        }
    } while (n != 11);
}