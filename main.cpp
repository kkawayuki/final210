#include <iostream>
#include <list> //DLL
using namespace std;

struct coffeeBooth //rename as needed
{
    string customerName, drinkOrder; //drinkorder int? 
    coffeeBooth *next; 
};



int main()
{
    list<coffeeBooth>coffeeQueue; //central DLL data structure
}