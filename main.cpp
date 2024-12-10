#include <iostream>
#include <list> //DLL
#include <array>
using namespace std;

struct coffeeBooth // rename as needed
{
    string customerName; // node values are Name and Order
    string drinkOrder;
};

int main()
{
    // array with names for customers/drinks, can be used in generation
    string dNames[] = {"Cappucino","Iced Coffee","Pumpkin Spice Latte","Coffee","Golden Brew","Yum Coffee","Tasty drink with caffine", "expensive drink"};
    string cNames[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Riley", "Jamie", "Dakota", "Reese", "Avery"};

    
    list<coffeeBooth> coffeeQueue; // central DLL data structure
}