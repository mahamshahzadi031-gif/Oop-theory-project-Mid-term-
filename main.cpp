#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(int d, int m, int y);
    Date(const Date &d);
    ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int d, int m, int y);
    void display() const;

    bool operator==(const Date &d) const;

    friend ostream &operator<<(ostream &out, const Date &d);
};

Date::Date() : day(1), month(1), year(2025) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}
Date::Date(const Date &d) : day(d.day), month(d.month), year(d.year) {}
Date::~Date() {}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
void Date::display() const { cout << day << "/" << month << "/" << year; }

bool Date::operator==(const Date &d) const
{
    return (day == d.day && month == d.month && year == d.year);
}
ostream &operator<<(ostream &out, const Date &d)
{
    out << d.day << "/" << d.month << "/" << d.year;
    return out;
}

class MenuItem
{
private:
    int itemId;
    char *itemName;
    string category;
    float price;
    bool isAvailable;

    static int totalItems;

public:
    MenuItem();
    MenuItem(int id, const char *name, string cat, float p);
    MenuItem(const MenuItem &m);
    ~MenuItem();

    MenuItem &operator=(const MenuItem &m);

    int getId() const;
    string getName() const;
    string getCategory() const;
    float getPrice() const;
    bool getAvailable() const;
    void setPrice(float p);
    void setAvailable(bool a);

    static int getTotalItems();

    bool operator==(const MenuItem &m) const;
    friend ostream &operator<<(ostream &out, const MenuItem &m);

    void display() const;
};

int MenuItem::totalItems = 0;

MenuItem::MenuItem()
    : itemId(0), itemName(nullptr), category(""), price(0.0f), isAvailable(true)
{
    itemName = new char[1];
    itemName[0] = '\0';
    totalItems++;
}

MenuItem::MenuItem(int id, const char *name, string cat, float p)
    : itemId(id), category(cat), price(p), isAvailable(true)
{
    itemName = new char[strlen(name) + 1];
    strcpy(itemName, name);
    totalItems++;
}

MenuItem::MenuItem(const MenuItem &m)
    : itemId(m.itemId), category(m.category),
      price(m.price), isAvailable(m.isAvailable)
{
    itemName = new char[strlen(m.itemName) + 1];
    strcpy(itemName, m.itemName);
    totalItems++;
}

MenuItem::~MenuItem()
{
    delete[] itemName;
    totalItems--;
}

MenuItem &MenuItem::operator=(const MenuItem &m)
{
    if (this != &m)
    {
        delete[] itemName;
        itemName = new char[strlen(m.itemName) + 1];
        strcpy(itemName, m.itemName);
        itemId = m.itemId;
        category = m.category;
        price = m.price;
        isAvailable = m.isAvailable;
    }
    return *this;
}

int MenuItem::getId() const { return itemId; }
string MenuItem::getName() const { return string(itemName); }
string MenuItem::getCategory() const { return category; }
float MenuItem::getPrice() const { return price; }
bool MenuItem::getAvailable() const { return isAvailable; }
void MenuItem::setPrice(float p) { price = p; }
void MenuItem::setAvailable(bool a) { isAvailable = a; }

int MenuItem::getTotalItems() { return totalItems; }

bool MenuItem::operator==(const MenuItem &m) const { return itemId == m.itemId; }

ostream &operator<<(ostream &out, const MenuItem &m)
{
    out << "[" << m.itemId << "] " << m.itemName
        << "  (" << m.category << ")"
        << "  PKR " << m.price
        << (m.isAvailable ? "  [Available]" : "  [Unavailable]");
    return out;
}
void MenuItem::display() const { cout << *this << endl; }

class Customer
{
private:
    int customerId;
    char *name;
    string contact;
    string address;
    float totalSpent;

    static int customerCount;

public:
    Customer();
    Customer(int id, const char *n, string con, string addr);
    Customer(const Customer &c);
    ~Customer();

    Customer &operator=(const Customer &c);

    int getId() const;
    string getName() const;
    string getContact() const;
    string getAddress() const;
    float getTotalSpent() const;
    void setContact(string c);
    void setAddress(string a);

    Customer &addSpending(float amount);
    Customer &updateAddress(string a);

    static int getCustomerCount();

    bool operator==(const Customer &c) const;
    friend ostream &operator<<(ostream &out, const Customer &c);

    void display() const;
};

int Customer::customerCount = 0;

Customer::Customer()
    : customerId(0), name(nullptr), contact(""), address(""), totalSpent(0.0f)
{
    name = new char[1];
    name[0] = '\0';
    customerCount++;
}

Customer::Customer(int id, const char *n, string con, string addr)
    : customerId(id), contact(con), address(addr), totalSpent(0.0f)
{
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    customerCount++;
}

Customer::Customer(const Customer &c)
    : customerId(c.customerId), contact(c.contact),
      address(c.address), totalSpent(c.totalSpent)
{
    name = new char[strlen(c.name) + 1];
    strcpy(name, c.name);
    customerCount++;
}

Customer::~Customer()
{
    delete[] name;
    customerCount--;
}

Customer &Customer::operator=(const Customer &c)
{
    if (this != &c)
    {
        delete[] name;
        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);
        customerId = c.customerId;
        contact = c.contact;
        address = c.address;
        totalSpent = c.totalSpent;
    }
    return *this;
}

int Customer::getId() const { return customerId; }
string Customer::getName() const { return string(name); }
string Customer::getContact() const { return contact; }
string Customer::getAddress() const { return address; }
float Customer::getTotalSpent() const { return totalSpent; }
void Customer::setContact(string c) { contact = c; }
void Customer::setAddress(string a) { address = a; }

Customer &Customer::addSpending(float amount)
{
    totalSpent += amount;
    return *this;
}
Customer &Customer::updateAddress(string a)
{
    address = a;
    return *this;
}

int Customer::getCustomerCount() { return customerCount; }

bool Customer::operator==(const Customer &c) const { return customerId == c.customerId; }

ostream &operator<<(ostream &out, const Customer &c)
{
    out << "ID: " << c.customerId
        << " | Name: " << c.name
        << " | Contact: " << c.contact
        << " | Address: " << c.address
        << " | Total Spent: PKR " << c.totalSpent;
    return out;
}
void Customer::display() const
{
    cout << "\n-------- Customer Details --------" << endl;
    cout << *this << endl;
    cout << "----------------------------------" << endl;
}

class Order
{
private:
    int orderId;
    Customer customer;
    MenuItem *items;
    int itemCount;
    int maxItems;
    Date orderDate;
    string status;
    float totalAmount;

    static int orderCount;

public:
    Order();
    Order(int id, Customer cust, Date d, int maxI = 10);
    Order(const Order &o);
    ~Order();

    Order &operator=(const Order &o);

    int getOrderId() const;
    Customer getCustomer() const;
    Date getOrderDate() const;
    string getStatus() const;
    float getTotalAmount() const;
    int getItemCount() const;

    Order &addItem(const MenuItem &item);
    Order &updateStatus(string s);
    Order &applyDiscount(float percent);

    static int getOrderCount();

    bool operator==(const Order &o) const;
    friend ostream &operator<<(ostream &out, const Order &o);

    void display() const;
};

int Order::orderCount = 0;

Order::Order()
    : orderId(0), customer(), orderDate(),
      itemCount(0), maxItems(10), status("Pending"), totalAmount(0.0f)
{
    items = new MenuItem[maxItems];
    orderCount++;
}

Order::Order(int id, Customer cust, Date d, int maxI)
    : orderId(id), customer(cust), orderDate(d),
      itemCount(0), maxItems(maxI), status("Pending"), totalAmount(0.0f)
{
    items = new MenuItem[maxItems];
    orderCount++;
}

Order::Order(const Order &o)
    : orderId(o.orderId), customer(o.customer), orderDate(o.orderDate),
      itemCount(o.itemCount), maxItems(o.maxItems),
      status(o.status), totalAmount(o.totalAmount)
{
    items = new MenuItem[maxItems];
    for (int i = 0; i < itemCount; i++)
        items[i] = o.items[i];
    orderCount++;
}

Order::~Order()
{
    delete[] items;
    orderCount--;
}

Order &Order::operator=(const Order &o)
{
    if (this != &o)
    {
        delete[] items;
        maxItems = o.maxItems;
        itemCount = o.itemCount;
        items = new MenuItem[maxItems];
        for (int i = 0; i < itemCount; i++)
            items[i] = o.items[i];
        orderId = o.orderId;
        customer = o.customer;
        orderDate = o.orderDate;
        status = o.status;
        totalAmount = o.totalAmount;
    }
    return *this;
}

int Order::getOrderId() const { return orderId; }
Customer Order::getCustomer() const { return customer; }
Date Order::getOrderDate() const { return orderDate; }
string Order::getStatus() const { return status; }
float Order::getTotalAmount() const { return totalAmount; }
int Order::getItemCount() const { return itemCount; }

Order &Order::addItem(const MenuItem &item)
{
    if (itemCount >= maxItems)
    {
        cout << "[!] Order is full!" << endl;
        return *this;
    }
    items[itemCount] = item;
    totalAmount += item.getPrice();
    itemCount++;
    return *this;
}

Order &Order::updateStatus(string s)
{
    status = s;
    return *this;
}

Order &Order::applyDiscount(float percent)
{
    totalAmount -= totalAmount * (percent / 100.0f);
    return *this;
}

int Order::getOrderCount() { return orderCount; }

bool Order::operator==(const Order &o) const { return orderId == o.orderId; }

ostream &operator<<(ostream &out, const Order &o)
{
    out << "Order #" << o.orderId
        << " | Customer: " << o.customer.getName()
        << " | Date: " << o.orderDate
        << " | Items: " << o.itemCount
        << " | Total: PKR " << o.totalAmount
        << " | Status: " << o.status;
    return out;
}

void Order::display() const
{
    cout << "\n========== ORDER DETAILS ==========" << endl;
    cout << *this << endl;
    cout << "  Customer Address: " << customer.getAddress() << endl;
    cout << "  Items Ordered:" << endl;
    for (int i = 0; i < itemCount; i++)
    {
        cout << "    " << items[i] << endl;
    }
    cout << "====================================" << endl;
}

class FoodDeliverySystem
{
private:
    string systemName;
    Customer **customers;
    Order **orders;
    MenuItem *menu;
    int maxCustomers;
    int maxOrders;
    int maxMenuItems;
    int currentCustomers;
    int currentOrders;
    int currentMenuItems;

    static int systemCount;
    const string dataFile;

    Customer *findCustomer(int id);
    Order *findOrder(int id);
    MenuItem *findMenuItem(int id);

public:
    FoodDeliverySystem(string name, int maxC, int maxO, int maxM);
    ~FoodDeliverySystem();

    void initializeMenu();

    void addMenuItem(int id, const char *name, string cat, float price);
    void displayMenu() const;
    void displayAvailableMenu() const;

    void addCustomer(int id, const char *name, string contact, string address);
    void removeCustomer(int id);
    void searchCustomer(int id) const;
    void displayAllCustomers() const;

    void placeOrder(int orderId, int customerId, int day, int month, int year);
    void addItemToOrder(int orderId, int menuItemId);
    void updateOrderStatus(int orderId, string status);
    void applyDiscountToOrder(int orderId, float percent);
    void viewOrder(int orderId) const;
    void displayAllOrders() const;
    void displayOrdersByCustomer(int customerId) const;

    void displayStats() const;
    string getSystemName() const;

    void saveToFile() const;
    void loadFromFile();

    static int getSystemCount();

    friend ostream &operator<<(ostream &out, const FoodDeliverySystem &f);
};

int FoodDeliverySystem::systemCount = 0;

FoodDeliverySystem::FoodDeliverySystem(string name, int maxC, int maxO, int maxM)
    : systemName(name), maxCustomers(maxC), maxOrders(maxO),
      maxMenuItems(maxM), currentCustomers(0), currentOrders(0),
      currentMenuItems(0), dataFile("orders_data.txt")
{

    customers = new Customer *[maxCustomers];
    orders = new Order *[maxOrders];
    menu = new MenuItem[maxMenuItems];

    for (int i = 0; i < maxCustomers; i++)
        customers[i] = nullptr;
    for (int i = 0; i < maxOrders; i++)
        orders[i] = nullptr;
    systemCount++;
    initializeMenu();
}

FoodDeliverySystem::~FoodDeliverySystem()
{
    for (int i = 0; i < currentCustomers; i++)
        delete customers[i];
    for (int i = 0; i < currentOrders; i++)
        delete orders[i];
    delete[] customers;
    delete[] orders;
    delete[] menu;
    systemCount--;
}

void FoodDeliverySystem::initializeMenu()
{
    struct
    {
        int id;
        const char *name;
        const char *cat;
        float price;
    } defaults[] = {
        {1, "Zinger Burger", "Burger", 350.0f},
        {2, "Chicken Pizza", "Pizza", 750.0f},
        {3, "Pepsi 500ml", "Drink", 80.0f},
        {4, "French Fries", "Snack", 150.0f},
        {5, "Chicken Shawarma", "Wrap", 220.0f},
        {6, "Veggie Burger", "Burger", 280.0f},
        {7, "Garlic Bread", "Snack", 120.0f},
        {8, "Chocolate Shake", "Drink", 180.0f},
    };
    int count = sizeof(defaults) / sizeof(defaults[0]);
    int limit = (count < maxMenuItems) ? count : maxMenuItems;
    for (int i = 0; i < limit; i++)
    {
        menu[currentMenuItems] = MenuItem(defaults[i].id, defaults[i].name,
                                          defaults[i].cat, defaults[i].price);
        currentMenuItems++;
    }
}

Customer *FoodDeliverySystem::findCustomer(int id)
{
    for (int i = 0; i < currentCustomers; i++)
        if (customers[i]->getId() == id)
            return customers[i];
    return nullptr;
}
Order *FoodDeliverySystem::findOrder(int id)
{
    for (int i = 0; i < currentOrders; i++)
        if (orders[i]->getOrderId() == id)
            return orders[i];
    return nullptr;
}
MenuItem *FoodDeliverySystem::findMenuItem(int id)
{
    for (int i = 0; i < currentMenuItems; i++)
        if (menu[i].getId() == id)
            return &menu[i];
    return nullptr;
}

void FoodDeliverySystem::addMenuItem(int id, const char *name, string cat, float price)
{
    if (currentMenuItems >= maxMenuItems)
    {
        cout << "[!] Menu is full!" << endl;
        return;
    }
    menu[currentMenuItems] = MenuItem(id, name, cat, price);
    currentMenuItems++;
    cout << "[+] Menu item added!" << endl;
}

void FoodDeliverySystem::displayMenu() const
{
    cout << "\n============= FULL MENU =============" << endl;
    for (int i = 0; i < currentMenuItems; i++)
        cout << menu[i] << endl;
}

void FoodDeliverySystem::displayAvailableMenu() const
{
    cout << "\n========== AVAILABLE MENU ===========" << endl;
    for (int i = 0; i < currentMenuItems; i++)
        if (menu[i].getAvailable())
            cout << menu[i] << endl;
}

void FoodDeliverySystem::addCustomer(int id, const char *name,
                                     string contact, string address)
{
    if (currentCustomers >= maxCustomers)
    {
        cout << "[!] Customer limit reached!" << endl;
        return;
    }
    for (int i = 0; i < currentCustomers; i++)
    {
        if (customers[i]->getId() == id)
        {
            cout << "[!] Customer ID already exists!" << endl;
            return;
        }
    }
    customers[currentCustomers] = new Customer(id, name, contact, address);
    currentCustomers++;
    cout << "[+] Customer registered!" << endl;
    saveToFile();
}

void FoodDeliverySystem::removeCustomer(int id)
{
    for (int i = 0; i < currentCustomers; i++)
    {
        if (customers[i]->getId() == id)
        {
            delete customers[i];
            customers[i] = customers[currentCustomers - 1];
            customers[currentCustomers - 1] = nullptr;
            currentCustomers--;
            cout << "[+] Customer removed!" << endl;
            saveToFile();
            return;
        }
    }
    cout << "[!] Customer not found!" << endl;
}

void FoodDeliverySystem::searchCustomer(int id) const
{
    for (int i = 0; i < currentCustomers; i++)
    {
        if (customers[i]->getId() == id)
        {
            customers[i]->display();
            return;
        }
    }
    cout << "[!] Customer not found!" << endl;
}

void FoodDeliverySystem::displayAllCustomers() const
{
    if (currentCustomers == 0)
    {
        cout << "  No customers yet." << endl;
        return;
    }
    cout << "\n========== ALL CUSTOMERS ===========" << endl;
    for (int i = 0; i < currentCustomers; i++)
        customers[i]->display();
}

void FoodDeliverySystem::placeOrder(int orderId, int customerId,
                                    int day, int month, int year)
{
    if (currentOrders >= maxOrders)
    {
        cout << "[!] Order limit reached!" << endl;
        return;
    }
    for (int i = 0; i < currentOrders; i++)
    {
        if (orders[i]->getOrderId() == orderId)
        {
            cout << "[!] Order ID exists!" << endl;
            return;
        }
    }
    Customer *c = findCustomer(customerId);
    if (c == nullptr)
    {
        cout << "[!] Customer not found!" << endl;
        return;
    }

    Date d(day, month, year);
    orders[currentOrders] = new Order(orderId, *c, d);
    currentOrders++;
    cout << "[+] Order placed! Now add items using option 9." << endl;
    saveToFile();
}

void FoodDeliverySystem::addItemToOrder(int orderId, int menuItemId)
{
    Order *o = findOrder(orderId);
    MenuItem *m = findMenuItem(menuItemId);
    if (o == nullptr)
    {
        cout << "[!] Order not found!" << endl;
        return;
    }
    if (m == nullptr)
    {
        cout << "[!] Menu item not found!" << endl;
        return;
    }
    if (!m->getAvailable())
    {
        cout << "[!] Item unavailable!" << endl;
        return;
    }

    o->addItem(*m);
    Customer *c = findCustomer(o->getCustomer().getId());
    if (c != nullptr)
        c->addSpending(m->getPrice());
    cout << "[+] " << m->getName() << " added to Order #" << orderId << endl;
    saveToFile();
}

void FoodDeliverySystem::updateOrderStatus(int orderId, string status)
{
    Order *o = findOrder(orderId);
    if (o == nullptr)
    {
        cout << "[!] Order not found!" << endl;
        return;
    }
    o->updateStatus(status);
    cout << "[+] Order #" << orderId << " status: " << status << endl;
    saveToFile();
}

void FoodDeliverySystem::applyDiscountToOrder(int orderId, float percent)
{
    Order *o = findOrder(orderId);
    if (o == nullptr)
    {
        cout << "[!] Order not found!" << endl;
        return;
    }

    o->applyDiscount(percent).updateStatus("Discounted");
    cout << "[+] " << percent << "% discount applied to Order #" << orderId << endl;
    cout << "    New Total: PKR " << o->getTotalAmount() << endl;
    saveToFile();
}

void FoodDeliverySystem::viewOrder(int orderId) const
{
    for (int i = 0; i < currentOrders; i++)
    {
        if (orders[i]->getOrderId() == orderId)
        {
            orders[i]->display();
            return;
        }
    }
    cout << "[!] Order not found!" << endl;
}

void FoodDeliverySystem::displayAllOrders() const
{
    if (currentOrders == 0)
    {
        cout << "  No orders yet." << endl;
        return;
    }
    cout << "\n============ ALL ORDERS ============" << endl;
    for (int i = 0; i < currentOrders; i++)
        orders[i]->display();
}

void FoodDeliverySystem::displayOrdersByCustomer(int customerId) const
{
    cout << "\n====== ORDERS FOR CUSTOMER #" << customerId << " ======" << endl;
    bool found = false;
    for (int i = 0; i < currentOrders; i++)
    {
        if (orders[i]->getCustomer().getId() == customerId)
        {
            orders[i]->display();
            found = true;
        }
    }
    if (!found)
        cout << "  No orders found for this customer." << endl;
}

void FoodDeliverySystem::displayStats() const
{
    cout << "\n======= SYSTEM STATISTICS =======" << endl;
    cout << *this << endl;
    cout << "  MenuItem objects : " << MenuItem::getTotalItems() << endl;
    cout << "  Customer objects : " << Customer::getCustomerCount() << endl;
    cout << "  Order objects    : " << Order::getOrderCount() << endl;
    cout << "  System instances : " << systemCount << endl;
}

string FoodDeliverySystem::getSystemName() const { return systemName; }
int FoodDeliverySystem::getSystemCount() { return systemCount; }

ostream &operator<<(ostream &out, const FoodDeliverySystem &f)
{
    out << "System : " << f.systemName
        << "  |  Customers: " << f.currentCustomers << "/" << f.maxCustomers
        << "  |  Orders: " << f.currentOrders << "/" << f.maxOrders
        << "  |  Menu Items: " << f.currentMenuItems;
    return out;
}

void FoodDeliverySystem::saveToFile() const
{
    ofstream file(dataFile);
    if (!file.is_open())
    {
        cout << "[!] Cannot open file!" << endl;
        return;
    }

    file << currentCustomers << "\n";
    for (int i = 0; i < currentCustomers; i++)
    {
        file << customers[i]->getId() << "\n";
        file << customers[i]->getName() << "\n";
        file << customers[i]->getContact() << "\n";
        file << customers[i]->getAddress() << "\n";
        file << customers[i]->getTotalSpent() << "\n";
    }

    file << currentOrders << "\n";
    for (int i = 0; i < currentOrders; i++)
    {
        file << orders[i]->getOrderId() << "\n";
        file << orders[i]->getCustomer().getId() << "\n";
        file << orders[i]->getOrderDate().getDay() << " "
             << orders[i]->getOrderDate().getMonth() << " "
             << orders[i]->getOrderDate().getYear() << "\n";
        file << orders[i]->getStatus() << "\n";
        file << orders[i]->getTotalAmount() << "\n";
        file << orders[i]->getItemCount() << "\n";
    }
    file.close();
    cout << "  [*] Data saved to '" << dataFile << "'" << endl;
}

void FoodDeliverySystem::loadFromFile()
{
    ifstream file(dataFile);
    if (!file.is_open())
    {
        cout << "  [*] No previous data. Starting fresh." << endl;
        return;
    }
    int count;

    file >> count;
    file.ignore();
    for (int i = 0; i < count && currentCustomers < maxCustomers; i++)
    {
        int id;
        float spent;
        string name, contact, address;
        file >> id;
        file.ignore();
        getline(file, name);
        getline(file, contact);
        getline(file, address);
        file >> spent;
        file.ignore();
        customers[currentCustomers] = new Customer(id, name.c_str(), contact, address);
        customers[currentCustomers]->addSpending(spent);
        currentCustomers++;
    }

    file >> count;
    file.ignore();
    for (int i = 0; i < count && currentOrders < maxOrders; i++)
    {
        int ordId, custId, d, m, y;
        float total;
        string status;
        int itemCnt;
        file >> ordId >> custId >> d >> m >> y;
        file.ignore();
        getline(file, status);
        file >> total >> itemCnt;
        file.ignore();
        Customer *c = findCustomer(custId);
        if (c != nullptr)
        {
            Date dt(d, m, y);
            orders[currentOrders] = new Order(ordId, *c, dt);
            orders[currentOrders]->updateStatus(status);
            currentOrders++;
        }
    }
    file.close();
    cout << "  [*] Data loaded from '" << dataFile << "'" << endl;
}

void displayMainMenu(const FoodDeliverySystem &fds)
{
    cout << "\n=============================================" << endl;
    cout << "       FOOD DELIVERY SYSTEM" << endl;
    cout << "       " << fds.getSystemName() << endl;
    cout << "=============================================" << endl;
    cout << " 1.  Add Customer" << endl;
    cout << " 2.  Remove Customer" << endl;
    cout << " 3.  Search Customer" << endl;
    cout << " 4.  Display All Customers" << endl;
    cout << " 5.  Display Full Menu" << endl;
    cout << " 6.  Display Available Menu" << endl;
    cout << " 7.  Add Menu Item" << endl;
    cout << " 8.  Place Order" << endl;
    cout << " 9.  Add Item to Order" << endl;
    cout << " 10. Update Order Status" << endl;
    cout << " 11. Apply Discount to Order" << endl;
    cout << " 12. View Order" << endl;
    cout << " 13. Display All Orders" << endl;
    cout << " 14. Orders by Customer" << endl;
    cout << " 15. Display Statistics" << endl;
    cout << " 16. Save Data to File" << endl;
    cout << " 0.  Exit" << endl;
    cout << "=============================================" << endl;
    cout << " Enter your choice: ";
}

int main()
{
    cout << "\n=================================================" << endl;
    cout << "   Welcome to Food Delivery System" << endl;
    cout << "   Maham Shahzadi  |  2025-CS-693" << endl;
    cout << "=================================================" << endl;

    FoodDeliverySystem *fds = new FoodDeliverySystem("QuickBite Express", 100, 200, 50);
    fds->loadFromFile();

    int choice;
    do
    {
        displayMainMenu(*fds);
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
        {
            int id;
            char name[100];
            string contact, address;
            cout << "\n--- Register Customer ---" << endl;
            cout << "Customer ID  : ";
            cin >> id;
            cin.ignore();
            cout << "Full Name    : ";
            cin.getline(name, 100);
            cout << "Contact No.  : ";
            getline(cin, contact);
            cout << "Address      : ";
            getline(cin, address);
            fds->addCustomer(id, name, contact, address);
            break;
        }

        case 2:
        {
            int id;
            cout << "Enter Customer ID to remove: ";
            cin >> id;
            fds->removeCustomer(id);
            break;
        }

        case 3:
        {
            int id;
            cout << "Enter Customer ID to search: ";
            cin >> id;
            fds->searchCustomer(id);
            break;
        }

        case 4:
            fds->displayAllCustomers();
            break;
        case 5:
            fds->displayMenu();
            break;
        case 6:
            fds->displayAvailableMenu();
            break;

        case 7:
        {
            int id;
            char name[100];
            string cat;
            float price;
            cout << "\n--- Add Menu Item ---" << endl;
            cout << "Item ID        : ";
            cin >> id;
            cin.ignore();
            cout << "Item Name      : ";
            cin.getline(name, 100);
            cout << "Category       : ";
            getline(cin, cat);
            cout << "Price (PKR)    : ";
            cin >> price;
            fds->addMenuItem(id, name, cat, price);
            break;
        }

        case 8:
        {
            int orderId, customerId, d, m, y;
            cout << "\n--- Place Order ---" << endl;
            cout << "Order ID      : ";
            cin >> orderId;
            cout << "Customer ID   : ";
            cin >> customerId;
            cout << "Order Date (DD MM YYYY): ";
            cin >> d >> m >> y;
            fds->placeOrder(orderId, customerId, d, m, y);
            break;
        }

        case 9:
        {
            int orderId, menuItemId;
            cout << "Order ID     : ";
            cin >> orderId;
            cout << "Menu Item ID : ";
            cin >> menuItemId;
            fds->addItemToOrder(orderId, menuItemId);
            break;
        }

        case 10:
        {
            int orderId;
            string status;
            cout << "Order ID : ";
            cin >> orderId;
            cin.ignore();
            cout << "New Status: ";
            getline(cin, status);
            fds->updateOrderStatus(orderId, status);
            break;
        }

        case 11:
        {
            int orderId;
            float percent;
            cout << "Order ID     : ";
            cin >> orderId;
            cout << "Discount (%) : ";
            cin >> percent;
            fds->applyDiscountToOrder(orderId, percent);
            break;
        }

        case 12:
        {
            int orderId;
            cout << "Order ID : ";
            cin >> orderId;
            fds->viewOrder(orderId);
            break;
        }

        case 13:
            fds->displayAllOrders();
            break;

        case 14:
        {
            int customerId;
            cout << "Customer ID : ";
            cin >> customerId;
            fds->displayOrdersByCustomer(customerId);
            break;
        }

        case 15:
            fds->displayStats();
            break;
        case 16:
            fds->saveToFile();
            break;

        case 0:
            cout << "\nSaving and exiting..." << endl;
            fds->saveToFile();
            break;

        default:
            cout << "[!] Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    delete fds;

    cout << "\nThank you for using QuickBite Express. Goodbye!" << endl;
    return 0;
}
