/// @brief This program will read a file with information about a phone, it will
/// store that information, analyze it, and print out a summary.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Global Constants
struct phone_type {
    static const int MAX_PHONE_APPS = 30;
    string brand;                           // brand of phone
    string model;                           // model of phone
    string owner;                           // owner of phone
    int storage_mb;                         // storage capactiy in MB
    int num_apps;                           // number of app installed
    string app_names[MAX_PHONE_APPS];       // names of apps - parallel array
    int app_sizes_mb[MAX_PHONE_APPS];       // size of apps - parallel array
    int total_app_size_mb;                  // total of all apps
};

// Function Prototypes
bool read_file(phone_type& phone, string filename);
void calculate_total(phone_type& phone);
void print_summary(const phone_type& phone);

int main(/*int argc, char* argv[]*/)
{
    //****** Declare Variables *********
    string filename;
    phone_type phone;

    cout << "Enter filename: ";
    cin >> filename;

    if (!read_file(phone, filename))
    {
        cout << "Error reading file.\n";
    }
    else
    {
        calculate_total(phone);
        print_summary(phone);
    }

    return 0;
}

// Function Definitions

/// @brief - Reads the phone data from a file into a teledevice_type object
/// @param - phone - [in/out] - the phone object to populate
/// @param - filename - [in] - name of the file to read
/// @return - true if successful, false otherwise
bool read_file(phone_type& phone, string filename)
{
    bool success = false;
    ifstream fin(filename);

    if (fin)
    {
        getline(fin, phone.brand, ' ');
        getline(fin, phone.model);

        getline(fin, phone.owner);
        fin >> phone.storage_mb;
        fin >> phone.num_apps;
        fin.ignore();

        for (int i = 0; i < phone.num_apps; i++)
        {
            string line;
            getline(fin, line);
            size_t colon_pos = line.find(':');
            phone.app_names[i] = line.substr(0, colon_pos);
            phone.app_sizes_mb[i] = stoi(line.substr(colon_pos + 1));
        }

        success = true;
        fin.close();
    }

    return success;
}

/// @brief - Calculates total size of all apps in the phone struct
/// @param - phone - [in/out] - the phone object to update
void calculate_total(phone_type& phone)
{
    phone.total_app_size_mb = 0;
    for (int i = 0; i < phone.num_apps; i++)
    {
        phone.total_app_size_mb += phone.app_sizes_mb[i];
    }
}

/// @brief - Prints a formatted summary of phone data
/// @param - phone - [in] - the phone object to print
void print_summary(const phone_type& phone)
{
    cout << "Phone brand and model: " << phone.brand
         << " " << phone.model << endl;
    cout << "Owner: " << phone.owner << endl;
    cout << "Storage Size: " << phone.storage_mb / 1024
         << "GB" << endl << endl;

    cout << left << setw(20) << "APP NAME"
         << right << setw(7) << "SIZE" << endl;

    for (int i = 0; i < phone.num_apps; i++)
    {
        cout << left << setw(20) << phone.app_names[i]
             << right << setw(7) << phone.app_sizes_mb[i] << endl;
    }

    cout << endl;
    cout << left << setw(20) << "TOTAL:"
         << right << setw(7) << phone.total_app_size_mb << endl;

    double percent = (phone.total_app_size_mb * 100.0) / phone.storage_mb;
    cout << left << setw(20) << "Percent Full:" << fixed << setprecision(1)
         << right << setw(7) << percent << endl;
}
