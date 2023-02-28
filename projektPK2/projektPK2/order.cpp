#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

order::order(std::string name, std::string secondName, std::string telephone, std::vector<std::pair<std::string, int>> orderedDishes)
{
    correctName(name);
    if (isNameCorrect(name))
        this->name = name;

    correctName(secondName);
    if (isNameCorrect(secondName))
        this->secondName = secondName;

    if (isTelephoneCorrect(telephone))
        this->telephone = telephone;

    for (std::size_t i = 0; i < orderedDishes.size(); i++)
    {
        this->orderedDishes.push_back({ orderedDishes[i].first, orderedDishes[i].second });
        totalPrice += orderedDishes[i].second;
    }
}

order::order(std::string name, std::string secondName, std::string telephone)
{
    correctName(name);
    if (isNameCorrect(name))
        this->name = name;

    correctName(secondName);
    if (isNameCorrect(secondName))
        this->secondName = secondName;

    if (isTelephoneCorrect(telephone))
        this->telephone = telephone;
}

void order::setName(std::string name)
{
    correctName(name);
    if (isNameCorrect(name))
        this->name = name;
}
void order::setSecondName(std::string secondName)
{
    correctName(secondName);
    if (isNameCorrect(secondName))
        this->secondName = secondName;
}
void order::setTelephone(std::string telephone)
{
    if (isTelephoneCorrect(telephone))
        this->telephone = telephone;
}
void order::setOrderedDishes(std::vector<std::pair<std::string, int>> orderedDishes)
{
    for (std::size_t i = 0; i < orderedDishes.size(); i++)
    {
        this->orderedDishes.push_back({ orderedDishes[i].first, orderedDishes[i].second });
        totalPrice += orderedDishes[i].second;
    }
}

std::string order::getName() const
{
    return this->name;
}
std::string order::getSecondName() const
{
    return this->secondName;
}
std::string order::getTelephone() const
{
    return this->telephone;
}
std::vector<std::pair<std::string, int>> order::getOrderedDishes() const
{
    return this->orderedDishes;
}
int order::getTotalPrice() const
{
    return this->totalPrice;
}

void order::orderDishesPushBack(std::string dish, int price)
{
    orderedDishes.push_back({ dish, price });
    totalPrice += price;
}

std::ostream& operator<<(std::ostream& str, order& o)
{
    str << "Klient:" << o.getName() << " " << o.getSecondName() << " " << o.getTelephone() << std::endl;
    str << "Zamowione dania: " << std::endl;

    for (std::size_t i = 0; i < o.orderedDishes.size(); i++)
    {
        str << o.orderedDishes[i].first << std::endl;
    }

    str << "Cena koncowa: " << o.totalPrice << std::endl;

    return str;
}