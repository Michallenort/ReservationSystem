#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<fstream>
#include<sstream>

#include "klasy.h"

int main()
{
    std::vector<reservation> r;
    std::vector<std::pair<std::string, int>> menu;
    std::vector<order> orders;
    std::pair<int, int> openHour{ 8, 30 }, closeHour{ 22, 0 };
    std::vector<table> tables;

    table t1(2);
    table t2(3);
    table t4(4);
    table t3(2);
    table t5(5);
    table t6(6);

    tables.push_back(t1);
    tables.push_back(t2);
    tables.push_back(t3);
    tables.push_back(t4);
    tables.push_back(t5);
    tables.push_back(t6);

    restaurantWithoutOrders sushi(tables, openHour, closeHour);

    restaurantWithOrders pizzeria(tables, openHour, closeHour, menu, orders);

    restaurant* bar;

    bar = &sushi;

    bar->menu();

    //bar = &pizzeria;

    //bar->menu();


    return 0;
}