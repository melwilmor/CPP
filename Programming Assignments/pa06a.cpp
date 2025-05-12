/// @brief This program is designed to decode a hidden message encoded with
/// arithmetic and ASCII.

#include <iostream>
#include <iomanip>

using namespace std;

// FUNCTION PROTOTYPES
bool read_expr(int& lhs, int& rhs, char& op);
int eval_expr(int lhs, int rhs, char op);
char to_char(int value);

int main() {
    //****** Declare Variables *********
    int lhs;             // Right hand side integer
    int rhs;             // Left hand side integer
    int result = 0;      // Outputted result
    char op = ' ';       // Operator characters
    char asciiChar;      // ASCII character to correspond with output

    while(read_expr(lhs, rhs, op))
    {
        // Use eval_expr to read through until EOF is met
        result = eval_expr(lhs, rhs, op);
        // Use read amounts to find ASCII character corresponding with value
        asciiChar = to_char(result);

    // ***** Output ********************
        cout << setw(6) << result << " (" << asciiChar << ")" << endl;
    }

    return result;
}

// FUNCTION DEFINITIONS

/// @brief Read a binary expression from standard input.
///
/// This function reads an integer operand, an integer operand, and an operator
/// (+, -, *, /, or %) from standard input and stores them in the provided
/// variables.
///
/// @param [out] lhs The first integer operand (output).
/// @param [out] rhs The second integer operand (output).
/// @param [out] op The operator (+, -, *, /, or %) (output).
///
/// @return True if a valid expression was read successfully, false otherwise.

bool read_expr(int& lhs, int& rhs, char& op)
{
    // Attempt to read. If fails, EOF is met.
    return static_cast<bool>(cin >> lhs >> op >> rhs);
}

/// @brief Evaluate a binary expression.
///
/// This function takes two integer operands and an operator (+, -, *, /, or %)
/// and calculates the result of the binary expression based on the provided
/// operator.
///
/// @param lhs The first integer operand (left operand).
/// @param rhs The second integer operand (right operand).
/// @param op The operator (+, -, *, /, or %) to apply to the operands.
///
/// @return The result of the binary expression.

int eval_expr(int lhs, int rhs, char op)
{
    int result;
    switch (op)
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            result = lhs / rhs;
            break;
        case '%':
            result = lhs % rhs;
            break;
        default:
            result = 0;
            break;
    }
    return result;

}

/// @brief Returns the character equivalent of a valid integer.
/// @param value The value to decode to ASCII.

char to_char(int value)
{
   return static_cast<char>(value);
}
