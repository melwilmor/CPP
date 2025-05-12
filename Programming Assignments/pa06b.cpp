/// @brief Program generates a summary of sales for the day, including amount
/// of each size cup and money collected.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Global constants: cup size in oz and prices
const int small_cup_size = 7;          // Oz in a sm cup
const int medium_cup_size = 11;        // Oz in a med cup
const int large_cup_size = 15;         // Oz in a lg cup
const double small_cup_price = 1.25;   // Sm cup price
const double medium_cup_price = 1.75;  // Med cup price
const double large_cup_price = 2.25;   // Lg cup price

// FUNCTION PROTOTYPES
void sell_punch(const string& size, int cups, int& small_cups_sold,
    int& medium_cups_sold, int& large_cups_sold, int& total_punch_sold,
    double& total_sales);
void show_cups_sold(int small_cups_sold, int medium_cups_sold,
    int large_cups_sold);
void show_total_punch_sold(int total_punch_sold);
void show_total_sales(double total_sales);

int main()
{
    // Declare variables
    int small_cups_sold = 0;            // Initialize sm cup counter
    int medium_cups_sold = 0;           // Initialize med cup counter
    int large_cups_sold = 0;            // Initialize lg cup counter
    int total_punch_sold = 0;           // Initialize oz of punch sold
    double total_sales = 0.0;           // Initialize income

    // Input & Process
    string size;
    int cups;
    while (cin >> size >> cups)
    {
        sell_punch(size, cups, small_cups_sold, medium_cups_sold,
        large_cups_sold, total_punch_sold, total_sales);
    }

    // Output
    cout << "Total cups sold:" << endl;
    show_cups_sold(small_cups_sold, medium_cups_sold, large_cups_sold);
    show_total_punch_sold(total_punch_sold);
    show_total_sales(total_sales);

    return 0;
}

// FUNCTION DEFINITIONS
/// @brief - A function to sell fruit punch
/// @param - [in] size - cup size
/// @param - [in] cups - number of cups ordered
/// @param - small_cups_sold - total of sm cups sold
/// @param - medium_cups_sold - total of med cups sold
/// @param - large_cups_sold - total of lg cups sold
/// @param - total_punch_sold - total of total cups sold
/// @param - total_sales - total of sales in dollars
void sell_punch(const string& size, int cups, int& small_cups_sold,
    int& medium_cups_sold, int& large_cups_sold, int& total_punch_sold,
    double& total_sales)
{
    if (size == "small")
    {
        small_cups_sold = small_cups_sold + cups;
        total_punch_sold = total_punch_sold + (cups * small_cup_size);
        total_sales = total_sales + (cups * small_cup_price);
    }
    else if (size == "medium")
    {
        medium_cups_sold = medium_cups_sold + cups;
        total_punch_sold = total_punch_sold + (cups * medium_cup_size);
        total_sales = total_sales + (cups * medium_cup_price);
    }
    else if (size == "large")
    {
        large_cups_sold = large_cups_sold + cups;
        total_punch_sold = total_punch_sold + (cups * large_cup_size);
        total_sales = total_sales + (cups * large_cup_price);
    }
}

/// @brief - A function to show the number of cups of each size sold
/// @param -  small_cups_sold - total sm cups sold
/// @param - medium_cups_sold - total med cups sold
/// @param - large_cups_sold - total lg cups sold
void show_cups_sold(int small_cups_sold, int medium_cups_sold,
    int large_cups_sold)
{
    cout << "Small:  " << small_cups_sold << endl;
    cout << "Medium: " << medium_cups_sold << endl;
    cout << "Large:  " << large_cups_sold << endl;
}

/// @brief - A function to show the total amount of punch sold
/// @param - total_punch_sold -total oz of cups sold
void show_total_punch_sold(int total_punch_sold)
{
    cout << "Total fruit punch sold: " << total_punch_sold << " oz" << endl;
}

/// @brief - A function to show the total sales
/// @param - total_sales - total sales for the day
void show_total_sales(double total_sales)
{
    cout << "Total sales: $" << fixed << setprecision(2) << total_sales << endl;

}
