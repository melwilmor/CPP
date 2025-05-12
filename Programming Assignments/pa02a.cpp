/// @brief This program will calculate the difference in cost between
/// gas vehicles and EV.

#include <iostream>

using namespace std;

int main() {
  /// Step 1: Declare Variables
  /// Declare the double variables needed at input.
  double evEfficiency;    // INPUT: Efficiency of EV per kWh
  double costPerkWh;      // INPUT: Cost of 1 kWh
  double gasEfficiency;   // INPUT: Efficiency of gas car per gal
  double costPerGal;      // INPUT: Cost of 1 gal
  /// Declare the double variables needed for cost per...
  double evCostTotal;     // OUTPUT: Cost per 100 miles for EV
  double gasCostTotal;    // OUTPUT: Cost per 100 miles for gas 
  /// Step 2: Input Phase
  /// Prompt user for the efficiency of EV and declare value.
  cout << "What is the efficiency of the EV in miles / kWh: ";
  cin >> evEfficiency;
  /// Prompt user for cost per kWh and declare value
  cout << "What is the cost per kWh: $";
  cin >> costPerkWh;
  /// Prompt user for the efficiency of gas and declare value.
  cout << "What is the efficiency of the gas car in miles / gallon: ";
  cin >> gasEfficiency;
  /// Prompt user for the cost per gallon and declare value.
  cout << "What is the cost per gallon: $";
  cin >> costPerGal;
  /// Step 3: Perform Calculations
  /// Find the cost of the EV per 100 miles.
  evCostTotal = (100 / evEfficiency) * costPerkWh;
  /// Find the cost of the gas car per 100 miles
  gasCostTotal = (100 / gasEfficiency) * costPerGal;
  /// Step 4: Output Phase
  cout << endl << endl; /// Create a blank line
  cout << "RESULTS";
  cout << endl << endl; /// Create a blank line 
  cout << "The cost per 100 miles for the EV is: $" << evCostTotal << endl;
  cout << "The cost per 100 miles for the gas car is: $" << gasCostTotal 
  << endl;
  return 0;
}

