/// @brief Practice with selection statements.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    const double EPSILON = 0.0001;      // tolerance
    int num1;                           // integers for input
    int num2;
    int num3;
    int temp;                           // swap variable

    double dbl1 = 3.0/7.0 + 2.0/7.0 + 2.0/7.0;
    double dbl2 = 1.0;

    int ret_val = 0;                    // default return value for program

    // ***** Input *********************
    cout << "Please enter 3 integers: ";
    cin >> num1 >> num2 >> num3;

    // ***** Process *******************
    if (!cin)
    {
        cout << "Error: Not enough numbers!" << endl;
        ret_val = 1;
    }
    else
    {
        if ( ( num2 <= num1) && (num2 <= num3) )
        {
            //num2 is less than num1 and less than num3
            // it must be the lowest
            // swap num2 with num1
            temp = num1;        // save old num1 in temp
            num1 = num2;        // change num1 to be lowest val found in num2
            num2 = temp;        // take saved old val of num1 and put it in num2
        }
        else if ( (num3 < num1) && (num3 < num2) )
        {
            // num3 is the lowest
            // swap num3 with num1
            temp = num1;
            num1 = num3;
            num3 = temp;
        }
          // ***** Output ********************
        cout << "Order: " << num1 << ',' << num2 << ',' << num3 << endl;
    }
    if ( fabs (dbl1 - dbl2) < EPSILON )
    {
        cout << "They are the same\n";
    }
    else
    {
        cout << "They are different\n";
    }

     return ret_val;
}
