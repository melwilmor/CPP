
/// @brief This program will read a text file and calculate the age of
/// each person and the average age of everyone in the file.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    /// Declare constants and variables
    const int CURR_YEAR = 2025;
    string name1;       /// name of person 1
    int year1;          /// birth year of person 1
    int age1;           /// CALC: age of person 1
    string name2;       /// name of person 2
    int year2;          /// birth year of person 1
    int age2;           /// CALC: age of person 2
    string name3;       /// name of person 3
    int year3;          /// birth year of person 3
    int age3;           /// CALC: age of person 3
    string name4;       /// name of person 4
    int year4;          /// birth year of person 4
    int age4;           /// CALC: age of person 4
    double avg_age;     /// CALC: average age of 4 people

    string filename;    /// name of input file
    ifstream fin;       /// file input stream
   
    /// Input
    cout << "Enter the name of the input file: ";
    cin >> filename;
  
    /// open file using ifstream variable
   fin.open(filename);
  
   /// read person 1 data
   getline(fin, name1, ':');
   fin >> year1;

   /// we need to get rid of the new line before reading the next line
   
   fin.ignore(1, '\n');

   /// read person 2 data
   getline(fin, name2, ':');
   fin >> year2;

   fin.ignore(1, '\n');
  
   /// read person 3 data
   getline(fin, name3, ':');
   fin >> year3;

   fin.ignore(1, '\n');

   /// read person 4 data
   getline(fin, name4, ':');
   fin >> year4;

   fin.ignore(1, '\n');
   /// close file
   fin.close(); 

   /// PROCESS
   /// calculate age for person 1
   age1 = CURR_YEAR - year1;

   /// calculate age for person 2
   age2 = CURR_YEAR - year2;

   /// calculate age for person 3
   age3 = CURR_YEAR - year3;

   /// calculate age for person 4
   age4 = CURR_YEAR - year4;

   /// calculate average age
   avg_age = (age1 + age2 + age3 + age4) / 4.0;

   /// OUTPUT
   cout << setw(15) << left << name1 << setw(5) << right << age1 << endl;
   cout << setw(15) << left << name2 << setw(5) << right << age2 << endl;
   cout << setw(15) << left << name3 << setw(5) << right << age3 << endl;
   cout << setw(15) << left << name4 << setw(5) << right << age4 << endl;
   
   cout << endl;
   
   cout << setw(15) << left << "Average Age: ";
   cout << setw(5) << right << avg_age << endl;
   
   return 0; 
}