/// @brief This is practice for structs

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Global Constants
struct bus_type
{
    string destination;
    static const size_t MAX_SEATS = 30;
    string names[MAX_SEATS];
    int ages[MAX_SEATS];
    size_t num_riders;
};

// Function Prototypes
bool read_file(bus_type& this_bus, string filename);
void print_bus(bus_type this_bus);

int main(int argc, char* argv[]) {
    //****** Declare Variables *********
    size_t how_many_riders;                // INPUT: Read from command line
    string dest;                        // INPIT: Read from command line
    string infilename;                  // INPUT: Read from command line
    bus_type mybus;                     // Struct variable

    // ***** Input *********************
    if (argc < 4)
    {
        cout << "Too few arguments. Please provide destination, number of "
             << "riders, and the filename to read in the riders.\n";
    }
    else if (argc > 4)
    {
        cout << "Too many arguments.\n";
    }
    else
    {
        // read values from command line
        dest = argv[1];
        how_many_riders = atoi(argv[2]);
        infilename = argv[3];

        // populate some struct members
        mybus.destination = dest;
        mybus.num_riders = how_many_riders;
        // read the file to populate the rest (name and ages)
        if (!read_file(mybus,infilename))
        {
            cout << "Error reading file.\n";
        }
        else
        {
            // ***** Process *******************

            // ***** Output ********************
            print_bus(mybus);
        }
    }
    return 0;
}

// Function Definitions
/// @brief - this reads the file for names and ages and populates the bus_type
/// struct. The bus_type struct has parallel arrays that hold names and ages
/// @param - [in/out] - the bus_type struct
/// @param - [in] - name of the file to read

bool read_file(bus_type& this_bus, string filename)
{
    ifstream fin;           // create INPUT file stream
    bool success;           // did the file reads work

    // open the file
    fin.open(filename);

    // read the file
    // repeat for the number of riders
    for (size_t i = 0; i < this_bus.num_riders; i++)
    {
        // read in the name into the array inside the struct
        fin >> this_bus.names[i];
        // read in the age into the array inside the struct
        fin >> this_bus.ages[i];
    }

    // check if anything caused an input failure
    success = fin.good() ? true : false;

    // close the file
    fin.close();

    // return success
    return success;
}
/// @brief - prints out the details in the bus struct
/// @param - the bus_type variable
void print_bus(bus_type this_bus)
{
    cout << "This bus is going to " << this_bus.destination << " with "
         << this_bus.num_riders << " passengers.\n";
    // print out a table header
    cout << setw(15) << "PASS";
    cout << setw(4) << "AGE";

    // go through list of passengers
    for (size_t i = 0; i < this_bus.num_riders; i++)
    {
        cout << setw(15) << this_bus.names[i];
        cout << setw(4) << this_bus.ages[i];
    }

}
