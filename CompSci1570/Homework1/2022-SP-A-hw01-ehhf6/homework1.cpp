// Programmer: Ethan Heckart date: 1/28/22
// File: homework1.cpp
// Purpose: Program a Schmealthy vending machine

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
/* ----------- VARIABLE DECLERATIONS --------------- */
float money = 0.0;
char keep_purchasing = 'y';
int product_num = 0;
int num_apple_bought = 0;
int num_LUG_bought = 0;
int num_pizza_bought = 0;
int num_HUG_bought = 0;
int num_banana_bought = 0;

/* ------------- INITIAL INPUT -------------- */
cout << fixed;
cout << setprecision(2);
cout << "This is the Schmending Machine! How much money do you have?" << endl;
cin >> money;

/* ------------- VENDING MACHINE OUTPUT ---------- */
while (keep_purchasing == 'y')
{
cout << "Enter product selection (1-5)" << endl;
cin >> product_num;
if (product_num == 1)
{
    if (money >= 1.50)
    {
        cout << "Purchased: Schmapple" << endl;
        money = money - 1.50;
        num_apple_bought = num_apple_bought + 1;
    }
    else if (money < 1.50)
    {
        cout << "Not enough funds!" << endl;
    }
    cout << "Keep purchasing? (y/n)" << endl;
    cin >> keep_purchasing;
}
if (product_num == 2)
{
    if (money >= 1.00)
    {
        cout << "Purchased: Lightly Used Grape" << endl;
        money = money - 1.00;
        num_LUG_bought = num_LUG_bought + 1;
    }
    else if (money < 1.00)
    {
        cout << "Not enough funds!" << endl;
    }
    cout << "Keep purchasing? (y/n)" << endl;
    cin >> keep_purchasing;
}
if (product_num == 3)
{
    if (money >= 0.50)
    {
        cout << "Purchased: Scent of a pizza" << endl;
        money = money - 0.50;
        num_pizza_bought = num_pizza_bought + 1;
    }
    else if (money < 0.50)
    {
        cout << "Not enough funds!" << endl;
    }
    cout << "Keep purchasing? (y/n)" << endl;
    cin >> keep_purchasing;
}
if (product_num == 4)
{
    if (money >= 1.25)
    {
        cout << "Purchased: Heavily Used Grape" << endl;
        money = money - 1.25;
        num_HUG_bought = num_HUG_bought + 1;
    }
    else if (money < 1.25)
    {
        cout << "Not enough funds!" << endl;
    }
    cout << "Keep purchasing? (y/n)" << endl;
    cin >> keep_purchasing;
}
if (product_num == 5)
{
    if (money >= 2.00)
    {
        cout << "Purchased: Banana?" << endl;
        money = money - 2.00;
        num_banana_bought = num_banana_bought + 1;
    }
    else if (money < 2.00)
    {
        cout << "Not enough funds!" << endl;
    }
    cout << "Keep purchasing? (y/n)" << endl;
    cin >> keep_purchasing;
}
}

/* ------------- RECEIPT OUTPUT ------------- */
cout << "" << endl;
cout << "You purchased:" << endl;
if (num_apple_bought > 0)
{
    cout << "Schmapple - " << num_apple_bought << endl;
}
if (num_LUG_bought > 0)
{
    cout << "Lightly Used Grape - " << num_LUG_bought << endl;
}
if (num_pizza_bought > 0)
{
    cout << "Scent of a Pizza - " << num_pizza_bought << endl;
}
if (num_HUG_bought > 0)
{
    cout << "Heavily Used Grape - " << num_HUG_bought << endl;
}
if (num_banana_bought > 0)
{
    cout << "Banana? - " << num_banana_bought << endl;
}
cout << "" << endl;
cout << "You have $" << money << " remaining. Have a Schmealthy day!";
return 0;
}