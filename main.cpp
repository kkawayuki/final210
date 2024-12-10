#include <iostream>
#include <list> //DLL
#include <array>
#include <random>
#include <time.h>
#include <deque>
using namespace std;

// global scope arrays with names used in generation
string cNames[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Riley", "Jamie", "Dakota", "Reese", "Avery", "Kevin", "Rowan", "Sawyer", "Blake", "Drew", "Emerson", "Skylar"};
string dNames[] = {"Cappucino", "Iced Coffee", "Pumpkin Spice Latte", "Coffee", "Golden Brew", "Yum Coffee", "Tasty drink with caffine", "expensive drink"};
string mNames[] = {"Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin", "Lemon Poppy Seed Muffin", "Cinnamon Streusel Muffin", "Apple Cinnamon Muffin", "Raspberry Almond Muffin", "Pumpkin Spice Muffin", "Double Chocolate Muffin", "Cranberry Orange Muffin"};
string bNames[] = {"Ziptie","Charm","Birthstone","Custom","Cool Rock","Awesome Rock","Love Charm","Luck Charm","Money Charm","OOP Class Success Charm","Kitty Charm"};

struct customer // parent class
{
    string customerName;
    string Order;

    // default constructor for random value initialization
    customer()
    {
        customerName = cNames[rand() % (cNames->size() - 1)]; // random customername/drinkorder name, -1 to avoid out of bounds behavior
    }

    // function to simplify output process
    void printInfo()
    {
        cout << customerName << ": " << Order;
    }
};

struct coffeeCustomer : public customer // use inheritance learned in CS200 to avoid redundancies where possible
{
    coffeeCustomer()
        : customer()
    {
        Order = dNames[rand() % (dNames->size() - 1)];
    }
};

struct muffinCustomer : public customer
{
    // inherit functionality from customer class

    muffinCustomer()
        : customer()
    {
        Order = mNames[rand() % (mNames->size() - 1)];
    }
};

struct braceletCustomer : public customer
{
    // inherit functionality from customer class

    braceletCustomer()
        : customer()
    {
        Order = bNames[rand() % (bNames->size() - 1)];
    }
};

struct braceletCustomer : public customer
{
    // inherit functionality from customer class

    braceletCustomer()
        : customer()
    {
        Order = bNames[rand() % (bNames->size() - 1)];
    }
};

// prototypes
void runDay(int, list<coffeeCustomer> &);

// MAIN ******************************************
int main()
{
    srand(time(0)); // seed random

    // coffeeShop
    list<coffeeCustomer> coffeeQueue; // central DLL data structure
    {                                 // indent for readability/collapsability in IDE
        // initialize
        for (int i = 0; i < 3; i++)
            coffeeQueue.push_back(coffeeCustomer()); // push back random customer to start

        cout << "INITIAL LINE: \n";
        for (auto it : coffeeQueue)
        {
            it.printInfo(); // print initial data
            cout << '\n';
        }
        cout << '\n';
    }

    deque<muffinCustomer> muffinDeque;

    // start simulation
    runDay(10, coffeeQueue);
}

// implementation
void runDay(int days, list<coffeeCustomer> &listCustomers) // change to accomodate other data structs
{
    int join = 0; // control to push_front

    for (int i = 0; i < days; i++) // for each day you want to sim
    {
        bool somethingHappens = false;

        cout << "DAY " << i + 1 << '\n';

        // guarantee to serve each iteration, so long as not empty line
        if (!listCustomers.empty())
        {
            cout << listCustomers.front().customerName << " with order: " << listCustomers.front().Order << " was served.\n";
            listCustomers.pop_front();
            somethingHappens = true;
        }

        //
        join = rand() % 2;
        if (join)
        {
            coffeeCustomer *temp = new coffeeCustomer();
            cout << temp->customerName << " with order: " << temp->Order << " joined the line!\n";

            listCustomers.push_back(*temp); // add customer to back
            somethingHappens = true;
        }

        if (!somethingHappens)
        {
            cout << "Nothing happened, store empty.\n";
        }
        cout << '\n';
    }
}