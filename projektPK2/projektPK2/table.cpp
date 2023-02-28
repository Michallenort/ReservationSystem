#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

table::table(int customersNumber, std::vector<reservation> reservations)
{
    this->customersNumber = customersNumber;

    for (auto i : reservations)
    {
        this->reservations.push_back(i);
    }
}
table::table(int customersNumber) { this->customersNumber = customersNumber; }

void table::setCustomerNumber(int customersNumber) { this->customersNumber = customersNumber; }
void table::setReservations(std::vector<reservation> reservations)
{
    for (auto i : reservations)
    {
        this->reservations.push_back(i);
    }
}

int table::getCustomersNumber() const { return this->customersNumber; }
std::vector<reservation> table::getReservations() const { return this->reservations; }