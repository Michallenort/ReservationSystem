#ifndef KLASY_H
#define KLASY_H

class customer
{
    std::string name, secondName, telephone;

public:
    customer() : name(""), secondName(""), telephone("") {};
    customer(std::string name, std::string secondName, std::string telephone);

    ~customer() {};

    void setName(std::string name);
    void setSecondName(std::string secondName);
    void setTelephone(std::string telephone);

    std::string getName() const;
    std::string getSecondName() const;
    std::string getTelephone() const;
};

class reservation
{
    customer client;
    std::pair<int, int> startHour, endHour;
    int day, month, year;

public:
    reservation() : client(), startHour(0, 0), endHour(0, 0), day(1), month(1), year(2000) {};
    reservation(customer client, std::pair<int, int> startHour, std::pair<int, int> endHour, int day, int month, int year);

    ~reservation() {};

    void setCustomer(std::string name, std::string secondName, std::string telephone);
    void setStartHour(int first, int second);
    void setEndHour(int first, int second);
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    customer getClient() const;
    std::pair<int, int> getStartHour() const;
    std::pair<int, int> getEndHour() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    friend std::ostream& operator<<(std::ostream& str, const reservation& r);
};

class table
{
    int customersNumber;
    std::vector<reservation> reservations;

public:
    table() : customersNumber(1) {};
    table(int customersNumber, std::vector<reservation> reservations);
    table(int customersNumber);

    ~table() { reservations.clear(); };

    void setCustomerNumber(int customersNumber);
    void setReservations(std::vector<reservation> reservations);

    int getCustomersNumber() const;
    std::vector<reservation> getReservations() const;

    friend class restaurant;
};

class restaurant
{
protected:
    std::vector<table> tables;
    std::pair<int, int> openHour, closeHour;

public:
    restaurant() : openHour(0, 0), closeHour(0, 0) {};
    restaurant(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour);
    restaurant(std::pair<int, int> openHour, std::pair<int, int> closeHour);

    ~restaurant() { tables.clear(); };

    void setTables(std::vector<table> tables);
    void setOpenHour(int first, int second);
    void setCloseHour(int first, int second);

    std::vector<table> getTables() const;
    std::pair<int, int> getOpenHour() const;
    std::pair<int, int> getCloseHour() const;

    void uploadFromFile(std::string fileName);
    void uploadToFile(std::string fileName);
    void reserveTable();
    void cancelReservation();
    bool checkTables(int year, int month, int day, std::pair<int, int> startHour, std::pair<int, int> endHour, int n, table t);
    void printReservations();

    virtual void menu(void) = 0;
};

class restaurantWithoutOrders: public restaurant
{
public:
    restaurantWithoutOrders() : restaurant() {};
    restaurantWithoutOrders(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour);
    restaurantWithoutOrders(std::pair<int, int> openHour, std::pair<int, int> closeHour);
    ~restaurantWithoutOrders() { tables.clear(); };

    void menu(void);

};

class order
{
    std::string name, secondName, telephone;
    std::vector<std::pair<std::string, int>> orderedDishes;
    int totalPrice = 0;
public:
    order() : name(""), secondName(""), telephone("") {};
    order(std::string name, std::string secondName, std::string telephone, std::vector<std::pair<std::string, int>> orderedDishes);
    order(std::string name, std::string secondName, std::string telephone);
    ~order() { orderedDishes.clear(); };
    void setName(std::string name);
    void setSecondName(std::string secondName);
    void setTelephone(std::string telephone);
    void setOrderedDishes(std::vector<std::pair<std::string, int>> orderedDishes);

    std::string getName() const;
    std::string getSecondName() const;
    std::string getTelephone() const;
    std::vector<std::pair<std::string, int>> getOrderedDishes() const;
    int getTotalPrice() const;

    void orderDishesPushBack(std::string dish, int price);

    friend std::ostream& operator<<(std::ostream& str, order& o);
};

class restaurantWithOrders : public restaurant
{
    std::vector<std::pair<std::string, int>> menuCard;
    std::vector<order> orders;

public:
    restaurantWithOrders() : restaurant() {};
    restaurantWithOrders(std::vector<table> tables, std::pair<int, int> openHour, std::pair<int, int> closeHour, std::vector<std::pair<std::string, int>> menuCard, std::vector<order> orders);
    restaurantWithOrders(std::pair<int, int> openHour, std::pair<int, int> closeHour);
    ~restaurantWithOrders() { tables.clear(); menuCard.clear(); orders.clear(); };

    void setMenuCard(std::vector<std::pair<std::string, int>> menuCard);
    void setOrders(std::vector<order> orders);

    std::vector<std::pair<std::string, int>> getMenuCard() const;
    std::vector<order> getOrders() const;

    void uploadMenuCard(std::string fileName);
    void printMenuCard();
    void addOrder();
    void removeOrder();
    void printOrders();
    void menu(void);
};

bool isHourCorrect(const std::pair<int, int> hour);

bool checkReservationHour(const std::pair<int, int> startHour1, const std::pair<int, int> endHour1, const std::pair<int, int> startHour2, const std::pair<int, int> endHour2);

bool checkHour(const std::pair<int, int> startHour1, const std::pair<int, int> endHour1, const std::pair<int, int> startHour2, const std::pair<int, int> endHour2);

bool isDateCorrect(const int year, const int month, const int day);

bool isNameCorrect(std::string name);

bool isTelephoneCorrect(std::string telephone);

bool checkYourChoice(std::vector<int> freeTables, int yourChoice);

void correctName(std::string& name);

#endif
