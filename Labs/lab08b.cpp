/// @brief This program demonstrates how to work with 2D arrays in C++.

#include <iostream>
#include <string>
#include <iomanip>

// Global Constants
const size_t DIM = 4;                 // Dimension/size of array

// Function Prototype
void print_2D_array(const int array[][DIM], size_t rows, size_t cols);
int sum_row(const int array[][DIM], size_t row, size_t cols);
int sum_col(const int array[][DIM], size_t rows, size_t col);

using namespace std;

int main() {
    //****** Declare Variables *********
    int matrix[DIM][DIM];

    // ***** Input *********************
    // go through every row
    for (size_t row = 0; row < DIM; row++) {
        // go through every column of that row
        for (size_t col = 0; col < DIM; col++) {
            // input element at this spot in the 2d array
            cin >> matrix[row][col];
        }
    }

    // print out the array immedately after input to check it
    print_2D_array(matrix,DIM,DIM);

    // ***** Process *******************

    // go through each row
    for (size_t row = 0; row < DIM; row++) {

        // get the sum of that row
        int sum = sum_row(matrix,row, DIM);
        // print the sum of that row
        cout << "Sum of row" << row << " is " << sum << endl;
    }

    // go through each column
    for (size_t col = 0; col < DIM; col++) {

        // get the sum of that column
        int sum = sum_col(matrix, DIM,col);
        // print the sum of that column
        cout << "Sum of column" << col << " is " << sum << endl;
    }

    // ***** Output ********************

    return 0;
}

// Function Definitions

/// @brief - prints a 2d array
/// @param - the 2d array of integers
/// @param - how many rows to print
/// @param - how many columns to print
void print_2D_array(const int array[][DIM], size_t rows, size_t cols)
{

    // go through every row
    for (size_t row = 0; row < DIM; row++) {

        // go through every column of the row
        for (size_t col = 0; col < DIM; col++) {

            // print each number in a width of 4
            cout << setw(4) << array[row][col];
        }

        // print new line
        cout << endl;
    }
}

/// @brief - sums up all values in one particular row
/// @param - a 2d array of integers
/// @param - the row we are interested in
/// @param - the number of columns in the row
/// @return - the sum of that row
int sum_row(const int array [][DIM], size_t row, size_t cols)
{
    int sum = 0;            // sum of numbers in particular row

    // go through every column of the row we are intered in
    for (size_t col = 0; col < cols; col++) {

        // add each element to the sum
        sum += array[row][col];
    }

    // return the answer
    return sum;
}

/// @brief - sums up al elements in one particular column
/// @param - the 2d array of integers
/// @param - how many rows there are
/// @param - the column we are interested in
int sum_col(const int array[][DIM], size_t rows, size_t col)
{
    int sum = 0;            // sum of numbers in particular column

    // go through every row of the column we are interested in
    for (size_t row = 0; row < rows; row++) {

        // add each element to the sum
        sum += array[row][col];
    }

    // return the answer
    return sum;
}
