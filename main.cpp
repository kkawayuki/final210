#include <iostream>
#include <list> //DLL, cannot use, implement my own
#include <array>
#include <random>
#include <time.h>
#include <deque>
#include <vector>
#include <stack> //for my data structure
using namespace std;

// global scope arrays with names used in generation
string cNames[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Riley", "Jamie", "Dakota", "Reese", "Avery", "Kevin", "Rowan", "Sawyer", "Blake", "Drew", "Emerson", "Skylar"};
string dNames[] = {"Cappucino", "Iced Coffee", "Pumpkin Spice Latte", "Coffee", "Golden Brew", "Yum Coffee", "Tasty drink with caffine", "expensive drink"};
string mNames[] = {"Blueberry Muffin", "Chocolate Chip Muffin", "Banana Nut Muffin", "Lemon Poppy Seed Muffin", "Cinnamon Streusel Muffin", "Apple Cinnamon Muffin", "Raspberry Almond Muffin", "Pumpkin Spice Muffin", "Double Chocolate Muffin", "Cranberry Orange Muffin"};
string bNames[] = {"Ziptie", "Charm", "Birthstone", "Custom", "Cool Rock", "Awesome Rock", "Love Charm", "Luck Charm", "Money Charm", "OOP Class Success Charm", "Kitty Charm"};
string lgsNames[] = {"Booster Box", "Booster Pack", "Plush", "Board Game", "Dice", "Deckbox", "Storage Box", "Trading Card Single", "Multiple Cards"}; // lgs = "local game store"

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

struct cardgameCustomer : public customer
{
    // inherit functionality from customer class

    cardgameCustomer()
        : customer()
    {
        Order = lgsNames[rand() % (lgsNames->size() - 1)];
    }
};

// implement coffeeBooth using DLL defined in midterm part 2: 
// Copied code below: 
// class DoublyLinkedList
// {
// private:
//     struct Customer
//     {
//         // fields of customer
//         string customerName;
//         string Order;
//         Customer *prev;
//         Customer *next;

//         // constructor
//         Customer(Customer *p = nullptr, Customer *n = nullptr)
//         {
//             customerName = cNames[rand() % (cNames->size() - 1)]; // take in string name as parameter
//             Order = dNames[rand() % (dNames->size() - 1)];
//             prev = p;
//             next = n;
//         }
//     };
//     Customer *head;
//     Customer *tail;

// public:
//     DoublyLinkedList()
//     {
//         head = nullptr;
//         tail = nullptr;
//     }

//     void push_back()
//     {
//         Customer *newCustomer = new Customer(); // make new customer
//         if (!tail)
//             head = tail = newCustomer;
//         else
//         {
//             tail->next = newCustomer;
//             newCustomer->prev = tail;
//             tail = newCustomer;
//         }
//     }

//     void pop_front()
//     {
//         if (!head)
//         {
//             cout << "List is empty." << endl;
//             return;
//         }

//         Customer *temp = head;

//         if (head->next)
//         {
//             head = head->next;
//             head->prev = nullptr;
//         }
//         else
//             head = tail = nullptr;

//         delete temp; 
//     }

//     ~DoublyLinkedList()
//     {
//         while (head)
//         {
//             Customer *temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
// };
//end copied code

// prototypes
void runDay(int, list<coffeeCustomer> &, deque<muffinCustomer> &, vector<braceletCustomer> &, stack<cardgameCustomer> &);

// MAIN ******************************************
int main()
{
    srand(time(0)); // seed random, NOTE: NAMES HIGHLY REPETITIVE DUE TO SPEED OF CONSTRUCTION

    // define various data structs
    list<coffeeCustomer> coffeeQueue; // this one should use a custom linked list
    deque<muffinCustomer> muffinDeque;
    vector<braceletCustomer> braceletVec;
    stack<cardgameCustomer> lgsStack; // mine uses a stack, which I'll have to manipulate to make similar?

    // initialize nodes for each
    for (int i = 0; i < 3; i++)
    {
        coffeeQueue.push_back(coffeeCustomer()); // push back random customer to start
        muffinDeque.push_back(muffinCustomer());
        braceletVec.push_back(braceletCustomer());
        lgsStack.push(cardgameCustomer());
    }

    // start simulation
    cout << "SIMULATION BEGINS!\n\n";
    runDay(10, coffeeQueue, muffinDeque, braceletVec, lgsStack);
}

// implementation
void runDay(int days, list<coffeeCustomer> &listCustomers, deque<muffinCustomer> &dequeMuffins, vector<braceletCustomer> &vecBracelets, stack<cardgameCustomer> &stackLGS) // change to accomodate other data structs
{
    int join = 0; // control to add new customer for each datatype

    for (int i = 0; i < days; i++) // for each day you want to sim
    {
        // rework logic to work for each data structure
        bool cOccurrence, mOccurrence, bOccurrence, tOccurrence;
        cOccurrence = mOccurrence = bOccurrence = tOccurrence = false;

        cout << "DAY " << i + 1 << '\n';

        // COFFEE SECTION
        { // NOTE: indentation so I can collapse sections while editing code if needed
            if (!listCustomers.empty())
            {
                cout << "COFFEE: " << listCustomers.front().customerName << " with order: " << listCustomers.front().Order << " was served.\n";
                listCustomers.pop_front();
                cOccurrence = true;
            }

            join = rand() % 2;
            if (join)
            {
                coffeeCustomer *temp = new coffeeCustomer();
                cout << "COFFEE: " << temp->customerName << " with order: " << temp->Order << " joined the line!\n";

                listCustomers.push_back(*temp); // add customer to back
                cOccurrence = true;
            }

            if (!cOccurrence)
            {
                cout << "Nothing happened at CoffeeStore today.\n";
            }
        }

        // MUFFIN SECTION
        {
            if (!dequeMuffins.empty())
            {
                cout << "MUFFIN: " << dequeMuffins.front().customerName << " with order: " << dequeMuffins.front().Order << " was served.\n";
                dequeMuffins.pop_front();
                mOccurrence = true;
            }

            join = rand() % 2;
            if (join)
            {
                muffinCustomer *temp = new muffinCustomer();
                cout << "MUFFIN: " << temp->customerName << " with order: " << temp->Order << " joined the line!\n";

                dequeMuffins.push_back(*temp); // add customer to back
                mOccurrence = true;
            }

            if (!mOccurrence)
            {
                cout << "Nothing happened at MuffinStore today.\n";
            }
        }

        // BRACELET SECTION
        {
            if (!vecBracelets.empty())
            {
                cout << "BRACELET: " << vecBracelets.front().customerName << " with order: " << vecBracelets.front().Order << " was served.\n";
                vecBracelets.erase(vecBracelets.begin()); // removes first element utilizing reference to beginning
                bOccurrence = true;
            }

            join = rand() % 2;
            if (join)
            {
                braceletCustomer *temp = new braceletCustomer();
                cout << "BRACELET: " << temp->customerName << " with order: " << temp->Order << " joined the line!\n";

                vecBracelets.push_back(*temp); // add customer to back
                mOccurrence = true;
            }

            if (!mOccurrence)
            {
                cout << "Nothing happened at BraceletStore today.\n";
            }
        }

        // LOCAL GAME STORE SECTION (Implemented via stack)
        {
            if (!stackLGS.empty())
            {
                cout << "GAME STORE: " << stackLGS.top().customerName << " with order: " << stackLGS.top().Order << " was served.\n";
                stackLGS.pop(); // can only add to/remove from top
                cOccurrence = true;
            }

            join = rand() % 2;
            if (join)
            {
                cardgameCustomer *temp = new cardgameCustomer();
                cout << "GAME STORE: " << temp->customerName << " with order: " << temp->Order << " joined the line!\n";

                stackLGS.push(*temp); // add customer to top of stack bypassing rest of line, (bad business practice.)
                cOccurrence = true;
            }

            if (!cOccurrence)
            {
                cout << "Nothing happened at GameStore today.\n";
            }
        }

        // to seperate days
        cout << '\n';
    }
}