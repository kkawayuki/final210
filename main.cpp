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
        customerName = cNames[rand()%cNames->size()];
        drinkOrder = dNames[rand()%dNames->size()];
    }

};


int main()
{
    srand(time(0)); //seed random

    list<customer> coffeeQueue; // central DLL data structure

    //test
    coffeeQueue.push_back(customer()); //push back default customer
    cout << coffeeQueue.front().customerName << " " << coffeeQueue.front().drinkOrder; 
}