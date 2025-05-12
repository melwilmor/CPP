/// @brief This program will analyze 4 inputted sides to determine if the values
/// are a quadralateral and, if so, which quadralateral it is.


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    //****** Declare Variables *********

    const double EPSILON = 0.001;       // tolerance
    int side1;                          // declare sides as integers
    int side2;
    int side3;
    int side4;

    // ***** Input *********************

    // Ask for the sides and print the prompts on a new line
    cout << "Enter the sides of a quadrilateral.\n";

    // Prompt for each side
    cout << "First Side:  ";
    cin >> side1;

    cout << "Second side: ";
    cin >> side2;

    cout << "Third side:  ";
    cin >> side3;

    cout << "Fourth side: " << endl;
    cin >> side4;

    // ***** Process *******************

    // Test if there were enough sides entered by the user

    if (!cin)
    {
        cout << "Error: Not enough sides!" << endl;
        return 1;
    }

    // If there were enough sides, test the sides to determine what quad. it is
    if (side1 >= side2 + side3 + side4 ||
        side2 >= side1 + side3 + side4 ||
        side3 >= side1 + side2 + side4 ||
        side4 >= side1 + side2 + side3) {
        cout << "This cannot be a quadrilateral" << endl;
    }
    else if (fabs(side1 - side2) < EPSILON &&
             fabs(side2 - side3) < EPSILON &&
             fabs(side3 - side4) < EPSILON) {
             cout << "Square" << endl;
    }
    else if (fabs(side1 - side3) < EPSILON &&
             fabs(side2 - side4) < EPSILON) {
             cout << "Rectangle" << endl;
    }
    else if (fabs(side1 - side3) < EPSILON ||
             fabs(side2 - side4) < EPSILON ||
             fabs(side1 - side2) < EPSILON ||
             fabs(side3 - side4) < EPSILON) {
             cout << "Trapezoid" << endl;
    }

    // Default to a different quad. if none of the other options are satisfied

    else { cout << "Other quadrilateral" << endl;
    }

    return 0;
}
