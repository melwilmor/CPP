/// @brief More practice with functions - void functions.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Prototypes
void square_and_cube(int num, int& square, int& cube);
void print_string(const string& str, int times);
void print_string(const string& str);
int sum(int num1, int num2 = 0, int num3 = 0);
void factorial_and_square(int num, int& factorial, int& square,
    bool square_only = true);

int main()
{
    // Declare variables
    int num;            // INPUT: the num to square and cube
    int square;         // CALC: num squared
    int cube;           // CALC: num cubed
    int factorial;      // CALC: factorial of num

    // Input
    cout << "Enter an integer: ";
    cin >> num;

    // Process
    // We send num into the function
    // The function calculates
    // function sends the cube and square back to main using reference params
    square_and_cube(num, square, cube);


    // Output
    cout << "The square is: " << square << endl;
    cout << "The cube is: " << cube << endl;
    print_string("Hello",3);
    print_string("Melanie");
    cout << sum(10, 11, 12) << endl;
    cout << sum(10, 11) << endl;
    cout << sum(10) << endl;

    factorial_and_square(num, factorial, square, false);
    cout << "Square is: " << square << endl;
    cout << "Factorial is: " << factorial << endl;

    factorial_and_square(num, factorial, square, true);
    cout << "Square is: " << square << endl;
    cout << "Factorial is: " << factorial << endl;

    factorial_and_square(num, factorial, square);
    cout << "Square is: " << square << endl;
    cout << "Factorial is: " << factorial << endl;


    return 0;
}

// FUNCTION DEFINITIONS

/// @brief - takes an int and returns its square and cube
/// @param [in] num - the integer input
/// @param [out] square - the square of the number
/// @param [out] cube - the cube of the number
void square_and_cube(int num, int& square, int& cube)
{
    square = num * num;
    cube = num * num * num;
    return;
}

/// @brief - takes a string and prints specified number of times
/// @param str - the string to print
/// @param times - number of times to print it
void print_string(const string& str, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << str << endl;
    }
}

/// @brief - takes a string and prince it once
/// @param str - the string to print
void print_string(const string& str)
{
    print_string(str, 1);
}

/// @brief - adds up to three numbers
/// @param num1 - first number
/// @param num2 - second number (default is 0)
/// @param num3 - third number (default is 0)
int sum(int num1, int num2, int num3)
{
 return num1 + num2 + num3;
}

/// @brief - takes an integer - returns the factorial and the square of that
/// number using reference parameters. If square_only is true - factorial is
/// zero.
/// @param [in] num - the number to work on
/// @param [out] factorial - the factorial of the number
/// @param [out] square - the square of the number
/// @param [in] square_only - option to only regturn the square and not the
/// factorial.
void factorial_and_square(int num, int& factorial, int& square,
    bool square_only)
{
    square = num * num;
    if (square_only)
    {
        factorial = 0;
    }
    else
    {
        int answer = 1;         // multiplication accumulator
        for (int i = 1; i <= num; i++)
        {
            answer = answer * i;
        }
        factorial = answer;
    }
}

