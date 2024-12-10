#include <iostream>
#include <list> //DLL
#include <array>
#include <random>
#include <time.h>
using namespace std;

//global scope arrays with names for customers/drinks, used in generation
string dNames[] = {"Cappucino","Iced Coffee","Pumpkin Spice Latte","Coffee","Golden Brew","Yum Coffee","Tasty drink with caffine", "expensive drink"};
string cNames[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Riley", "Jamie", "Dakota", "Reese", "Avery", "Kevin"};

struct customer
{
    string customerName;
    string drinkOrder;

    //default constructor for random value initialization
    customer()
    {
        customerName = cNames[rand()%(cNames->size()-1)]; //random customername/drinkorder name, -1 to avoid out of bounds behavior
        drinkOrder = dNames[rand()%(dNames->size()-1)];
    }

    //function to simplify output process
    void printInfo()
    {
        cout << customerName << ": " << drinkOrder; 
    }

};

//prototypes
void runDay(int, list<customer>&);

//MAIN ******************************************
int main()
{
    srand(time(0)); //seed random

    list<customer> coffeeQueue; // central DLL data structure

    //initialize
    for(int i = 0; i < 3; i++)
        coffeeQueue.push_back(customer()); //push back random customer to start

    runDay(10, coffeeQueue);
}

//implementation
void runDay(int days, list<customer>&listCustomers)
{
    int join = 0; //control to push_front

    for(int i = 0; i < days; i++) //for each day you want to sim
    {
        //test
        join = rand()%2;
        cout << join << '\n';


    }
}