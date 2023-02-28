#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

bool isHourCorrect(const std::pair<int, int> hour)
{
    if (hour.first >= 0 && hour.first <= 23)
    {
        if (hour.second >= 0 && hour.second <= 59)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

bool checkReservationHour(const std::pair<int, int> startHour1, const std::pair<int, int> endHour1, const std::pair<int, int> startHour2, const std::pair<int, int> endHour2)
{
    if (startHour2.first >= endHour1.first)
    {
        if (startHour2.first > endHour1.first)
            return true;
        else if (startHour2.first == endHour1.first && startHour2.second >= endHour1.second)
            return true;
        else
            return false;
    }
    else if (endHour2.first <= startHour1.first)
    {
        if (endHour2.first < startHour1.first)
            return true;
        else if (endHour2.first == startHour1.first && endHour2.second <= startHour1.second)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

bool checkHour(const std::pair<int, int> startHour1, const std::pair<int, int> endHour1, const std::pair<int, int> startHour2, const std::pair<int, int> endHour2)
{
    if (endHour2.first > startHour2.first || (endHour2.first == startHour2.first && endHour2.second > startHour2.second))
    {
        if (startHour2.first > startHour1.first && startHour2.first < endHour1.first)
        {
            if (startHour1.first < endHour2.first && endHour2.first < endHour1.first)
            {
                return true;
            }
            else if (endHour2.first == endHour1.first && endHour2.second <= endHour1.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (startHour2.first == startHour1.first && startHour2.second >= startHour1.second)
        {
            if (startHour1.first < endHour2.first && endHour2.first < endHour1.first)
            {
                return true;
            }
            else if (endHour2.first == endHour1.first && endHour2.second <= endHour1.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }


}

bool isDateCorrect(const int year, const int month, const int day)
{
    if (year >= 2021 && year <= 2030)
    {
        if (month >= 1 && month <= 12)
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (day >= 1 && day <= 31)
                    return true;
                else
                    return false;
            }
            else if (month == 4 || month == 6 || month == 9 || month == 11)
            {
                if (day >= 1 && day <= 30)
                    return true;
                else
                    return false;
            }
            else if (month == 2)
            {
                if (day >= 1 && day <= 28)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool isNameCorrect(std::string name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]))
        {
            return false;
        }
    }

    return true;
}

bool isTelephoneCorrect(std::string telephone)
{
    if (telephone.length() == 9)
    {
        for (int i = 0; i < telephone.length(); i++)
        {
            if (!isdigit(telephone[i]))
            {
                return false;
            }
        }

        return true;
    }
    else
        return false;
}

bool checkYourChoice(std::vector<int> freeTables, int yourChoice)
{
    for (std::size_t i = 0; i < freeTables.size(); i++)
    {
        if (freeTables[i] == yourChoice)
            return true;
    }
    return false;
}

void correctName(std::string& name)
{
    name[0] = toupper(name[0]);

    for (std::size_t i = 1; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }

}