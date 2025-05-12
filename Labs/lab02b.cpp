
#include <iostream>

using namespace std;

int main() {
   /// Constant Definitions
   const double DECIMAL = 5.50;    /// Double Constant 
   const double payRate = 20.0;    /// Double Constant
   const string blanks = " ";      /// Constant for output formatting
   /// Variable declarations
   int height;                     /// INPUT:integer variale
   int weight;                     /// INPUT:integer variable
   unsigned int hoursWorked;       /// INPUT: unassigned integer variable
   double discount10;              /// CALC: double variable
   double billingAmount;           /// CALC: double variable
   double bonus;                   /// CALC: double variable
   double price;                   /// CALC: double variable

   /// ***** Input *********************
   height = 6;
   weight = 156;
   hoursWorked = 45;
   price = 49.9;
   /// ***** Process *******************
    discount10 = (2 * height + weight) / 10;
    billingAmount = price * (1 - discount10 / 100) - DECIMAL;
    bonus = --hoursWorked * payRate / 50;
   /// ***** Output ********************
    cout << height << " " << weight << endl;
    cout << price << " " << billingAmount << endl;
    cout << "Bonus = " << bonus << endl;
    
    return 0;
}
