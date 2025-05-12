/// @brief This program reads multiple binary expressions with two duodecimal
/// operands and a single integer operator from a standard input.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototypes
bool to_int(const string& duodecimal, int& value);
string to_duodecimal(int value);
bool is_valid_operator(char op);

int main() {
    int count = 0;;
    cin >> count;
    cin.ignore();   // ignore newline after the number

    for (int caseNum = 1; caseNum <= count; caseNum++) {
        string operand1 = "";
        string operand2 = "";
        char op = '\0';

        // Extract operand1 and operand2 from input file
        cin >> operand1 >> op >> operand2;

        int val1 = 0;
        int val2 = 0;

        bool valid1 = to_int(operand1, val1);
        bool valid2 = to_int(operand2, val2);
        bool validOp = is_valid_operator(op);

        int result = 0;
        bool validOperation = true;

        if (!valid1 || !valid2 || !validOp) {
            validOperation = false;
        }

        if (validOperation) {
            // Eval. expression based on the operator
            switch (op) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    if (val2 == 0) {
                        validOperation = false;
                    } else {
                        result = val1 / val2;
                    }
                    break;
                case '%':
                    if (val2 == 0) {
                        validOperation = false;
                    } else {
                        result = val1 % val2;
                    }
                    break;
                default: {
                    validOperation = false;
                }
        }

        // Output the result or an error msg - whichever is applicable
        if (!validOperation) {
            cout << "Case " << caseNum << ": " << to_duodecimal(result) << endl;
        } else {
            cout << "Case " << caseNum << ": invalid expression" << endl;
            }
        }
    }
}

// Function definitions

/// @brief Converts a duodecimal (base-12) string to an integer value.
/// This function takes a string representing a number in duodecimal format and
/// converts it to its integer equivalent. It can handle both positive and
/// negative numbers, and is case-insensitive to the letters 'A' and 'B' which
/// represent the values 10 and 11 respectively. The function performs
/// validation on the input string to ensure it contains only valid duodecimal
/// digits. In case of an empty string or a string containing invalid
/// characters, the function returns false, and the output integer value
/// remains unchanged.
/// @param duodecimal The duodecimal string to convert. It should contain only
/// the characters [0-9] or [Aa-Bb], and optionally a leading '-' for negative
/// numbers.
/// @param [out] value The converted integer value.
/// @return True if the conversion is successful and the string is a valid
/// duodecimal number. False otherwise.
bool to_int(const string& duodecimal, int& value)
{
    value = 0;
    int start = 0;
    bool isNegative = false;

    if (duodecimal.length() == 0) {
        return false;
    }

    if (duodecimal.at(0) == '-') {
        isNegative = true;
        start = 1;
        if (start == duodecimal.length()) {
            return false;
        }
    }

    for (int i = start; i < duodecimal.length(); i++) {
        char ch = toupper(duodecimal.at(start)); // Normalize to uppercase
        int digit = 0;


        if (isdigit(ch)) {
            digit = ch - '0';
        } else if (ch == 'A') {
            digit = 10;
        } else if (ch == 'B') {
            digit = 11;
        } else {
            return false;       // Invalid character
        }

        value = value * 12 + digit;
    }

    if (isNegative) {
        value = -value;
    }

    return true;
}

/// @brief Converts an integer value to its duodecimal (base-12) string
/// representation.
/// This function takes an integer and converts it to a string representing
/// the corresponding number in duodecimal format. It handles negative numbers
/// by prefixing the result with a minus sign. The conversion handles the full
/// range of integer values supported by the `int` data type.
/// @param value The integer value to convert to duodecimal format. Can be any
/// integer, positive or negative.
/// @return A string representing the number in duodecimal format. If the input
/// is zero, the function returns "0". For negative numbers, the result is
/// prefixed with a '-'.
string to_duodecimal(int value)
{
    if (value == 0) {
        return "0";
    }

    bool isNegative = false;
    if (value < 0) {
        isNegative = true;
        value = -value;
    }

    string result = "";

    while (value > 0) {
        int remainder = value % 12;
        char digit = '0';

        if (remainder < 10) {
            digit = '0' + remainder;
        } else if (remainder == 10) {
            digit = 'A';
        } else {            // remainder == 11
            digit = 'B';
        }

        result.insert(0, 1, digit);
        value = value / 12;
    }

    if (isNegative) {
        result.insert(0, 1, '-');
    }

    return result;
}

/// @brief Validates if a character is a supported arithmetic operator. This
/// function checks if the provided character is one of the valid arithmetic
/// operators: +, -, *, /, or %.
/// @param op The character to validate as an operator.
/// @return True if the character is a valid operator, false otherwise.
bool is_valid_operator(char op)
{
    return (op == '+') || (op == '-') || (op == '*') || (op == '/') ||
    (op == '%');
}
