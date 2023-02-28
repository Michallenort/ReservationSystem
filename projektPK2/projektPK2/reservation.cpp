#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

reservation::reservation(customer client, std::pair<int, int> startHour, std::pair<int, int> endHour, int day, int month, int year)
{
    this->client = client;
    this->startHour = startHour;
    this->endHour = endHour;
    this->day = day;
    this->month = month;
    this->year = year;
}

void reservation::setCustomer(std::string name, std::string secondName, std::string telephone)
{
    client.setName(name);
    client.setSecondName(secondName);
    client.setTelephone(telephone);
}
void reservation::setStartHour(int first, int second)
{
    this->startHour.first = first;
    this->startHour.second = second;
}
void reservation::setEndHour(int first, int second)
{
    this->endHour.first = first;
    this->endHour.second = second;
}
void reservation::setDay(int day) { this->day = day; }
void reservation::setMonth(int month) { this->month = month; }
void reservation::setYear(int year) { this->year = year; }

customer reservation::getClient() const { return this->client; }
std::pair<int, int> reservation::getStartHour() const { return this->startHour; }
std::pair<int, int> reservation::getEndHour() const { return this->endHour; }
int reservation::getDay() const { return this->day; }
int reservation::getMonth() const { return this->month; }
int reservation::getYear() const { return this->year; }

std::ostream& operator<<(std::ostream& str, const reservation& r)
{
    str << "Klient: " << r.client.getName() << " " << r.client.getSecondName() << " " << r.client.getTelephone() << std::endl;
    str << "Data: ";
    if (r.day < 10)
        std::cout << 0 << r.day << ".";
    else
        std::cout << r.day << ".";

    if (r.month < 10)
        std::cout << 0 << r.month << ".";
    else
        std::cout << r.month << ".";

    std::cout << r.year << std::endl;
    str << "Godziny: "; 

    if (r.startHour.first < 10)
        std::cout << 0 << r.startHour.first << ":";
    else
        std::cout << r.startHour.first << ":";

    if (r.startHour.second < 10)
        std::cout << 0 << r.startHour.second << " - ";
    else
        std::cout << r.startHour.second << " - ";

    if (r.endHour.first < 10)
        std::cout << 0 << r.endHour.first << ":";
    else
        std::cout << r.endHour.first << ":";

    if (r.endHour.second < 10)
        std::cout << 0 << r.endHour.second  << std::endl;
    else
        std::cout << r.endHour.second << std::endl;
    return str;
}