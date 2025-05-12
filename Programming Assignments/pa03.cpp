/// @brief This program helps extract data from a .txt file and read it to
/// compile it into an easy-to-read format.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int  main(){
    /// Declare variables
    string name1;       /// first person's last name
    string fname1;      /// first person's first name
    ///char  middle1;      /// first person's middle name
    int sec1;           /// first person's section
    double price1;      /// first person's cost
    string name2;       /// second person's last name
    string fname2;      /// second person's first name
    ///char middle2;       /// second persons middle name
    int sec2;           /// second person's section
    double price2;      /// second person's cost
    string name3;       /// third person's last name
    string fname3;      /// third person's first name
    ///char middle3;       /// third person's middle name
    int sec3;           /// third person's section
    double price3;      /// third person's cost
    string name4;       /// fourth person's last name
    string fname4;      /// fourth person's first name
    ///char middle4;       /// fourth person's middle name
    int sec4;           /// fourth person's section
    double price4;      /// fourth person's cost

    double avg_price;   /// Average price

    string filename;    /// name of input
    ifstream fin;       /// file input stream

    /// Input
    cout << "Enter the input filename: ";
    cin >> filename;

    fin.open(filename); /// opening file

    /// read all 4 people's data

   fin >> sec1 >> price1;
   fin.ignore();
   getline(fin, name1, ',');
   getline(fin, fname1);

   fin >> sec2 >> price2;
   fin.ignore();
   getline(fin, name2, ',');
   getline(fin, fname2);

   fin >> sec3 >> price3;
   fin.ignore();
   getline(fin, name3, ',');
   getline(fin, fname3);
   
   fin >> sec4 >> price4;
   fin.ignore();
   getline(fin, name4, ',');
   getline(fin, fname4);
    
   fin.close();         /// close file

   /// PROCESS
   /// CALC: average price
   avg_price = (price1 + price2 + price3 + price4) / 4.0;

   /// OUTPUT

   /// Display average price
   cout << setw(10) << left << "Average: ";
   cout << setw(5) << fixed << setprecision(2) << right << avg_price << endl;

   /// blank line
   cout << endl;

   ///border

   /// output all info
   cout << setw(25) << left << "NAME" << setw(6) << right << "SECTION" <<
   setw(9) << right << "PRICE" <<  endl;

   cout << setfill('-') << setw(42) <<  "" << endl;
   cout << setfill(' ');
   
   cout << setw(27) << left << (fname1 + ' ' + name1) 
   << setw(3) << right << sec1 
   << setw(12) << fixed << setprecision(2) << right << price1 << endl;
   cout << setw(27) << left << (fname2 + ' ' + name2) 
   << setw(3) << right << sec2 
   << setw(12) << fixed << setprecision(2) << right << price2 << endl;
   cout << setw(27)<< left << (fname3 + ' '+ name3) 
   << setw(3) << right << sec3 
   << setw(12) << fixed << setprecision(2) << right << price3 << endl;
   cout << setw(27) << left << (fname4 + ' ' + name4) 
   << setw(3) << right << sec4 
   << setw(12) << fixed << setprecision(2) << right << price4 << endl;

  cout << setfill('-') << setw(42) << "" << endl;
  cout << setfill(' ');
    return 0;
}
