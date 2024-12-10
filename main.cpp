#include <iostream>
#include <list> //DLL
#include <array>
#include <random>
#include <time.h>
using namespace std;

// global scope arrays with names for customers/drinks, used in generation
string dNames[] = {"Cappucino", "Iced Coffee", "Pumpkin Spice Latte", "Coffee", "Golden Brew", "Yum Coffee", "Tasty drink with caffine", "expensive drink"};
string cNames[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Riley", "Jamie", "Dakota", "Reese", "Avery", "Kevin", "Rowan", "Sawyer", "Blake", "Drew", "Emerson", "Skylar"};

struct customer
{
    string customerName;
    string drinkOrder;

    // default constructor for random value initialization
    customer()
    {
        customerName = cNames[rand() % (cNames->size() - 1)]; // random customername/drinkorder name, -1 to avoid out of bounds behavior
        drinkOrder = dNames[rand() % (dNames->size() - 1)];
    }

    // function to simplify output process
    void printInfo()
    {
        cout << customerName << ": " << drinkOrder;
    }
};

// prototypes
void runDay(int, list<customer> &);

// MAIN ******************************************
int main()
{
    srand(time(0)); // seed random

    list<customer> coffeeQueue; // central DLL data structure

    // initialize
    for (int i = 0; i < 3; i++)
        coffeeQueue.push_back(customer()); // push back random customer to start

    cout << "INITIAL LINE: \n";
    for (auto it : coffeeQueue)
    {
        it.printInfo(); // print initial data
        cout << '\n';
    }
    cout << '\n';

    // start simulation
    runDay(10, coffeeQueue);
}

// implementation
void runDay(int days, list<customer> &listCustomers)
{
    int join = 0; // control to push_front
    

    for (int i = 0; i < days; i++) // for each day you want to sim
    {
        bool somethingHappens = false;

        cout << "DAY " << i + 1 << '\n';

        // guarantee to serve each iteration, so long as not empty line
        if (!listCustomers.empty())
        {
            cout << listCustomers.front().customerName << " with order: " << listCustomers.front().drinkOrder << " was served.\n";
            listCustomers.pop_front();
            somethingHappens = true;
        }

        //
        join = rand() % 2;
        if (join)
        {
            customer *temp = new customer();
            cout << temp->customerName << " with order: " << temp->drinkOrder << " joined the line!\n";

            listCustomers.push_back(*temp); // add customer to back
            somethingHappens = true;
        }

        if(!somethingHappens)
        {
            cout << "Nothing happened, store empty."
        }
        cout << '\n';
    }
}