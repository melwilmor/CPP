/// @brief This program is practice for writing user-defined functions.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// FUNCTION PROTOTYPES
int add(int lhs, int rhs);
int subtract(int lhs, int rhs);

// MAIN
int main() {
    //****** Declare Variables *********
    int num1;               // INPUT: first number input by user
    int num2;               // INPUT: second number input by user
    int sum;                // CALC: sum of two input
    int diff;               // CALC: difference of two inputs
    double avg;             // CALC: average of sum and difference
    double square_root;     // CALC: square root of the average

    // ***** Input *********************
    cout << "Enter an integer: ";
    cin >> num1;

    cout << "Enter another integer: ";
    cin >> num2;
    // ***** Process *******************
    sum = add(num1, num2);
    diff = subtract(num1, num2);

    // average of the two results not of the two input values
    // divide by 2.0 so that we get a double result
    avg = (sum + diff) / 2.0;

    square_root = sqrt(avg);

    // ***** Output ********************
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Average: " << avg << endl;
    cout << "Square Root: " << square_root << endl;

    return 0;
}

// FUNCTION DEFINITIONS

/// @brief This function takes the two parameters, adds them together, and
/// returns the result.
/// @param lhs integer left hand operand
/// @param rhs integer right hand operand
/// @return the integer sum
int add(int lhs, int rhs)
{
    return lhs + rhs;
}

/// @brief This function takes the two parameters, subtracts the second from
/// the first, and returns the result.
/// @param lhs integer left hand operand
/// @param rhs integer right hand operand
/// @return the integer difference
int subtract(int lhs, int rhs)
{
    return lhs - rhs;
}

