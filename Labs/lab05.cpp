/// @brief Practice with menues, input validation, and loops.

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int EXIT = 2;     // Sentinel to stop the menu system
    int user_choice;        // menu choice the user selects
    int lowest = 210000000; // lowest number so far
    int input_num;          // number the user enters
    int counter = 0;        // how many numbers are input


    do
    {
        // ***** Input *********************
        // Show menu

        cout << "Please select from the following options: \n";
        cout << "1. Input another number.\n";
        cout << "2. Exit.\n";

        // Get selection
        cout << "Your selection: ";
        cin >> user_choice;

        // ***** Process *******************
        // Do selections
        if (user_choice == 1)
        {
            // get the new number
            cout << "Enter integer: ";
            cin >> input_num;
            while (input_num  % 2 == 0)
            {
                // if the number is not odd - show error message;
                cout << "Odd numbers only please\n";
                // ask them for a new number
                cout << "Enter integer: ";
                cin >> input_num;
            }

            if (input_num < 0)
            {
                // if its a negative number - error message only
                // dont ask for more inputs
                cout << "ERROR: positive numbers only.\n";
            }

            else
            {
                // only check if its the lowest and add to counter if its +
                if (counter == 0)
                {
                    // this is the very first number we got
                    lowest = input_num;
                }
                else
                {
                    // check if its the lowest
                    if (input_num < lowest)
                    {
                        // replace old lowest number with new number if lower
                        lowest = input_num;
                    }
                }
                // increase the count of numbers inputted
                counter++;
            }
        }
        else if (user_choice == 2)
        {
            cout << "Goodbye\n";
            cout << "The smallest number was: " << lowest << endl;
        }
        else
        {
            cout << "ERROR - that's not a valid menu choice\n";
        }

        // ***** Output ********************
    } while (user_choice != EXIT);

    return 0;
}