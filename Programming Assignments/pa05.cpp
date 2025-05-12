/// @brief This program will analyze a customer's inputs and process them
/// through a banking system.

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //****** Declare Variables *********
    double deposit;                 // user input deposit
    double withdraw;                // user input withdraw
    int user_choice;                // menu choice
    double balance = 0.0;           // acct balance
    const int EXIT = 4;             // sentinel value
    int counter = 0;                // how many valid transactions occured
    double largeTransaction = 0.0;  // largest transaction
    double smallTransaction = 0.0;  // small transaction
    double totalTransaction = 0.0;  // all transactions summed

    // Welcome msg
    cout << "Welcome to the Simple Banking System!\nYour balance is now: $" <<
    fixed << setprecision(2) << balance << endl;

    do {
        // show menu
        cout << "\n1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check balance\n";
        cout << "4. Exit\n";
        cout << "\nPlease select an option: ";
        cin >> user_choice;

        // validate that the user chooses a valid menu option
        if (user_choice < 1 || user_choice > 4)
            {
                cout << "NOT A VALID CHOICE.\n";
            }
        // Deposit money
        if (user_choice == 1)
            {
                do {
                    cout << "Enter the amount to deposit: ";
                    cin >> deposit;

                    // check to see if the amount is negative
                    if (deposit <= 0)
                        {
                            cout << "THE AMOUNT MUST BE POSITIVE.\n\n";
                        }
                }
                // loop until valid entry
                while (deposit <= 0);
                // once valid entry is achieved
                {
                    balance += deposit;
                    cout << "Your deposit has been processed.\n";
                    counter++;
                    totalTransaction += deposit;
                    // initialize lg/sm transaction amts if first input
                    if (counter == 1)
                        {
                            largeTransaction = deposit;
                            smallTransaction = deposit;
                        }
                    // verify if transaction is the smallest/largest so far
                    else
                        {
                            if (deposit > largeTransaction)
                                {
                                    largeTransaction = deposit;
                                }
                            if (deposit  < smallTransaction)
                                {
                                smallTransaction = deposit;
                                }
                        }
                }
            }
        // withdraw input
        if (user_choice == 2) {
            do {
                    cout << "Enter the amount to withdraw: ";
                    cin >> withdraw;

                // loop until input is valid
                if (withdraw <= 0)
                    {
                        cout << "THE AMOUNT MUST BE POSITIVE.\n\n";
                    }

            } while (withdraw <= 0);

            // check if withdraw amount is larger than balance. return home if
            // insufficient balance is found
            if (withdraw > balance)
                {
                    cout << "INSUFFICIENT BALANCE.\n";
                }
            // process withdraw
            else
            {
                balance -= withdraw;
                cout << "Your withdrawal has been processed.\n";
                counter++;
                totalTransaction += withdraw;
                if (counter == 1)
                    {
                        largeTransaction = withdraw;
                        smallTransaction = withdraw;
                    }
                else
                    {
                        if (withdraw > largeTransaction)
                            {
                                largeTransaction = withdraw;
                            }
                        if (withdraw < smallTransaction)
                            {
                                smallTransaction = withdraw;
                            }
                    }
            }
        }
        // check balance
        if (user_choice == 3)
            {
                cout << "Your balance is now: $" << fixed << setprecision(2)
                << balance << endl;
            }
    }
    while (user_choice != EXIT);
    // Compute
    { const double avgTransaction = totalTransaction / counter;

    cout << "Goodbye!\n";
    cout << "\nNumber of transactions: " << counter << endl;
    cout << "Largest transaction:    $" << fixed << setprecision(2) <<
    largeTransaction << endl;
    cout << "Smallest transaction:   $" << fixed << setprecision(2) <<
    smallTransaction << endl;
    cout << "Average Transaction:    $" << fixed << setprecision(2) <<
    avgTransaction << endl;
    cout << "Final balance:          $" << fixed << setprecision(2) <<
    balance << endl;
    }
    return 0;
}
