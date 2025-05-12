/// @brief More practice with structs - this time an array of structs.

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

// Global Constants and Declarations
const int MAX_PERSONS = 10;
const int CURRENT_YEAR = 2025;

struct person_t
{
    string name;
    int age;
};

// Function Prototypes
void write_ppl(person_t ppl[], size_t size);

// Main

int main(int argc, char* argv[]) {
    //****** Declare Variables *********
    person_t ppl[MAX_PERSONS];          // an array of person_t structs

    // ***** Input *********************
    if (argc < 4)
    {
        cout << "Not enough arguments: need number of people, and then"
             << " list of names and ages.\n";
    }
    else
    {
        int num_ppl = atoi(argv[1]);
        if (argc < (2 + (2 * num_ppl)))
        {
            // number of arguments needs to be 2 (for the program name and
            // num of ppl) and then 2 more for each person (name and age)
            cout << "Not enough arguments: need number of people, and then"
                 << " list of names and ages.\n";
        }
        else
        {
            // rest of our program
            for (int i = 0; i < num_ppl; i++)
            {
                // index of first person name is 2 (i is 0)
                // index of second person name is 4 (i is 1)
                // index of third person name is 6 (i is 2)
                // index of fourth person name is 8 (i is 3)
                // etc ...
                ppl[i].name = argv[(i + 1) * 2];
                // index of the first person age is 3 (i is 0)
                // index of the second person age is 5 (i is 1)
                // index of the third person age is 7 (i is 2)
                // index of the fourth person age is 9 (i is 3)
                // etc ...
                ppl[i].age = atoi(argv[((i + 1) * 2) + 1]);
            }

            // write info into file
            write_ppl(ppl, num_ppl);
        }
    }

    // ***** Process *******************

    // ***** Output ********************

    return 0;
}

// Function Definitions
/// @brief - this will write the people in the person_t array to a file
/// the name of the file will be lab09b-output.txt
/// @param - ppl[] - the person_t array
/// @param - size - size of the array
void write_ppl(person_t ppl[], size_t size)
{
    ofstream fout;                  // file output stream
    int calc_year;                  // year the person we are printing was born

    // open the file
    fout.open("lab09b-output.txt");

    // process (write) to the file
    fout << "a8000614809" << endl;
    fout << "Melanie" << endl;

    // loop through people
    for (size_t i = 0; i < size; i++)
    {
        // calculate the year they were born
        calc_year = CURRENT_YEAR - ppl[i].age;
        // write out their info
        fout << ppl[i].name << " was born in " << calc_year << endl;
    }

    // close the file
    fout.close();
}
