/// @brief This program is practice for arrays.

#include <iostream>
#include <string>

using namespace std;

// Global constant
const int MAX_SIZE = 20;

// Function Prototypes
void selection_sort(int list[], size_t length);
bool is_ascending(int list[], size_t length);
void print_array(int list[], size_t length);

int main() {
    //****** Declare Variables *********
    int nums[MAX_SIZE];                 // array of integers
    size_t n;                           // number of integers we will input

    // ***** Input *********************
    cout << "How many integers will you enter? : ";
    cin >> n;

    if ( n > MAX_SIZE)
    {
        cout << "Sorry - we cannot handle your request." << endl;
    }
    else
    {
        // the rest of the program
        // input n numbers
        for (size_t i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        // ***** Process *******************
        if (is_ascending(nums,n))
        {
            // its ascending
            cout << "The sequence is in ascending order." << endl;
        }
        else
        {
            // its not ascending
            print_array(nums,n);
            selection_sort(nums,n);
        }
        // ***** Output ********************
        print_array(nums,n);

    }
    return 0;
}

// Function Definitions

/// @brief this function sdorts a list of integerrs from least to most
/// @param list - an integer array
/// @param length - the size of the array
void selection_sort(int list[], size_t length)
{
    // in the beggining the whole list is unsorted
    // the unsorted portion starts at the variable st_of_unsort
    // and goes to the end of the array
    for (size_t st_of_unsort = 0; st_of_unsort < length - 1; st_of_unsort++)
    {
        // find the smallest number in the unsorted portion of the list
        // start by assuming the first one is smallest
        size_t smallest = st_of_unsort;

        // check the second number to the last number to see if any are smaller
        for (size_t this_one = st_of_unsort + 1; this_one < length; this_one++)
        {
            if (list[this_one] < list[smallest])
            {
                // this one we are looking at now is smaller than the smallest
                // that means this one is the new smallest
                smallest = this_one;
            }
        }

        // swap the smallest and first number in the unsorted part of the list
        int temp;
        temp = list[smallest];
        list[smallest] = list[st_of_unsort];
        list[st_of_unsort] = temp;
    }
}

/// @brief this function tells us if an integer array is ascending
/// @param list - the array of integers
/// @param length - the size of the array
/// @return - true if the list is ascending, false if not
bool is_ascending(int list[], size_t length)
{
    bool result = true;             // assuming that we are ascending

    // go through every item - from the first to the second to last
    for (size_t i = 0; i < length - 1; i++)
    {
        // compare each item with its next item
        if (list[i] > list[i+1])
        {
            // if its not less than or equal - we are not ascending
            result = false;
        }
    }

    return result;
}

/// @brief prints an array
/// @param list -  an integer array
/// @param length - the size of the array
void print_array(int list[], size_t length)
{
    // Range based loop
    for (size_t i = 0; i < length; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
