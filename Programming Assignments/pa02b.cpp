/// @brief This program will calculate how long it would take to fully
/// drain Lake Mead at its current capacity.

#include <iostream>

using namespace std;

int main(){
    // *** Input ***
    // Define Constants
    /// Max capacity in acre-feet
    const double MaxCapacityAcreFt = 28.23e6;
    /// Conversion from acre-feet to gallons
    const double acreft_gal = 325851.75;
    /// Conversion from cubic feet to gallons
    const double cuft_gal = 7.48052;

    /// Input Variables
    /// Lake's current capacity in percentage
    double lakeCapPercent;
    /// Flow rate in cu ft / second
    double flowRateCFS;

    /// User input
    cout << "How full is Lake Mead currently (provide percentage): ";
    cin >> lakeCapPercent;

    cout << "What is the flow rate through the hoover dam (cubic feet per second): ";
    cin >> flowRateCFS;

    // ** Process **
    
    /// Calculate the amount of water in acre-feet and gallons
    double currentCapacityAcreFt = (lakeCapPercent / 100) * MaxCapacityAcreFt;
    double currentCapacityGal = currentCapacityAcreFt * acreft_gal;

    // Calculate the time to drain lake in seconds
    double flowRateGalPerSec = flowRateCFS * cuft_gal;
    int timeToDrainSec = currentCapacityGal / flowRateGalPerSec;

    // Convert time to H:M:S
    int hour = timeToDrainSec / 3600;
    int min = (timeToDrainSec % 3600) / 60;
    int sec = timeToDrainSec % 60;

    // *** Output **
    cout << endl << endl;
    cout << "RESULTS:" << endl;
    cout << "Draining " << currentCapacityAcreFt << " acre feet or " << 
    currentCapacityGal << " gallons of water " << endl;
    cout << "at a rate of " << flowRateCFS << " cubic feet per second" << endl;
    cout << " would take" << hour << ":" << min << ":" << sec << endl;

    return 0;
}
