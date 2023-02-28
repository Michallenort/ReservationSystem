#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

restaurantWithoutOrders::restaurantWithoutOrders(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour)
{
    for (auto i : tables)
    {
        this->tables.push_back(i);
    }

    this->openHour = openHour;
    this->closeHour = closeHour;
}

restaurantWithoutOrders::restaurantWithoutOrders(std::pair<int, int> openHour, std::pair<int, int> closeHour)
{
    this->openHour = openHour;
    this->closeHour = closeHour;
}

void restaurantWithoutOrders::menu(void)
{
    std::cout << "Witamy w naszej restauracji!\nCo masz zamiar zrobic?:" << std::endl;
    int n = 0;
    do
    {

        std::cout << "1.Zarezerwuj stolik.\n2.Odwolaj rezerwacje.\n3.Wyswietl rezerwacje.\n4.Pobierz rezerwacje z pliku.\n5.Zapisz rezerwacje w pliku.\n6.Zakoncz." << std::endl;
        std::cout << "Co wybierasz?:";

        std::cin >> n;
        std::cout << std::cin.fail();

        if (std::cin.fail())
        {
            std::cout << "To nie jest liczba calkowita!" << std::endl;
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

    } while (n != 6);
}