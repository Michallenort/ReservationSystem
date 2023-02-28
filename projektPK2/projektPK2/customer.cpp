#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

customer::customer(std::string name, std::string secondName, std::string telephone)
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

void customer::setName(std::string name)
{
    correctName(name);
    if (isNameCorrect(name))
        this->name = name;
}
void customer::setSecondName(std::string secondName)
{
    correctName(secondName);
    if (isNameCorrect(secondName))
        this->secondName = secondName;
}
void customer::setTelephone(std::string telephone)
{
    if (isTelephoneCorrect(telephone))
        this->telephone = telephone;
}

std::string customer::getName() const { return this->name; }
std::string customer::getSecondName() const { return this->secondName; }
std::string customer::getTelephone() const { return this->telephone; }