#include <iostream> 

using namespace std;

int main()
{
    // Step 1: Variable Declarations
    // Declare one variable each of char, int data types
    char c;              /// INPUT: character variable
    int inum;            /// INPUT: integer variable
    // Declare 3 variables of the double data type
    // called 'dblval', 'sum', and 'product'
    double dblval;       /// double variable
    double sum;          /// CALC: double variable
    double product;      /// CALC: double variable
    // Declare 3 more int variables called 'hours', 'mins', and 'secs'
    int hours;           /// CALC: hours variable
    int mins;            /// CALC: minute variable
    int secs;            /// CALC: seconds variable
    
    // Step 2: Input Phase (Prompt and Read Values)
    // Prompt the user for a char input using cout
    cout << "Please enter a character: ";
    // Read the char input from the user using cin
    cin >> c;
    
    // Prompt the user for an int input using cout
    cout << "Please enter an integer: ";
    // Read the int input from the user using cin
    cin >> inum;
    
    // Prompt the user for a dblval input using cout
    cout << "Please enter a floating point number: ";
    // Read the double input from the user using cin
    cin >> dblval;
    // do not read the remaining variables

    // Step 3: Process Phase
    // add the int variable and double variable and 
    // assign it to 'sum'
    sum = inum + dblval;

    // multiply the int and double variables and assign 
    // it to 'product'
    product = inum * dblval;

    // Assuming the integer value we input is in seconds
    // Calculate and assign how many hours, minutes, seconds it equates to
    hours = inum / 3600;
    mins = (inum % 3600) / 60;
    secs = (inum % 3600) % 60;
  
    // Step 4: Output Phase (Display Labels and Values)
    // Display the word "Char:" and the value of the char variable using cout
    cout << "Char: " << c << endl; 
    // Display the word "Int:" and the value of the int variable using cout
    cout << "Int: " << inum << endl;
    // Display the word "Double:" and the value of the variable using cout
    cout << "Double: " << dblval << endl; 
    // Display the word "Sum: " and the value of the variable using cout
    cout << "Sum: " << sum << endl;
    // Display the word "Product: " and the value of the variable using cout
    cout << "Product: " << product << endl;
    // Display the hours, minutes, seconds in the format H:M:S
    cout << hours << ":" << mins << ":" << secs << endl;
    
    return 0;
}