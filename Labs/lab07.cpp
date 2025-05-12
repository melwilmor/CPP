#include <cctype>
#include <iostream>
#include <string>

/** DEFINE THE FOLLOWING FOUR FUNCTIONS */

/// Converts a digit character into its integer value.
/// @param c The digit character to convert.
/// @return  The integer value of the digit character, or
///          zero if non-digit character
int char_to_int(char c);

/// Converts an integer value to its corresponding character.
/// @param n The integer to convert.
/// @return The character representation of the digit.
char int_to_char(int n);

/// Reverses the given string using insertions.
/// @param input The string to reverse.
/// @return The reversed string.
std::string reverse_string(const std::string& input);

/// Converts a string to its uppercase equivalent.
/// @param input The string to convert to uppercase.
/// @return A new string with all alphabetic characters converted to uppercase.
std::string to_uppercase(const std::string& input);

/** DO NOT ALTER THESE FUNCTION PROTOTYPES OR THEIR DEFINITIONS */
bool check(bool condition, const std::string& msg = "");
void char_to_int_conversion_tests();
void int_to_char_conversion_tests();
void reverse_string_tests();
void to_uppercase_tests();

int main() {
    // call each of the test functions to validate your function definitions
    char_to_int_conversion_tests();
    int_to_char_conversion_tests();
    reverse_string_tests();
    to_uppercase_tests();

    return 0;
}

/// Converts a digit character into its integer value.
/// @param ch The digit character to convert.
/// @return The integer value of the digit character, or
///         zero if non-digit character
int char_to_int(char ch) {
    // TODO - take the character '0' and turn it into integer 0
    int result;

    if (isdigit(ch))
    {
        result = static_cast<int>(ch) - static_cast<int>('0');
    }
    else
    {
        result = 0;
    }
    return result;
}

/// Converts an integer value to its corresponding character.
/// @param value The integer to convert.
/// @return The character representation of the digit.
char int_to_char(int value) {

    char result;
    // take the integer value of the 0 character and add it to our integer
    // then take the result of that and convert it to a character
    result = static_cast<char>(value + static_cast<int>('0'));

    return result;
}

/// Reverses the given string using insertions.
/// @param str The string to reverse.
/// @return The reversed string.
std::string reverse_string(const std::string& str) {
    // TODO

    std::string newString = "";

    // go through each char one at a time in forward direction
    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);            // grab char at that spot
        newString.insert(0,1,ch);       //insert that char into front of new str
    }

    return newString;
}

/// Converts a string to its uppercase equivalent.
/// @param str The string to convert to uppercase.
/// @return A new string with all alphabetic characters converted to uppercase.
std::string to_uppercase(const std::string& str) {
    // TODO
    std::string newString = "";

    // go through each char one at a time in forward direction
    for (std::string::size_type i = 0; i < str.size(); i++)
    {
        char ch = str.at(i);                          // grab char at that spot
        char ucase = static_cast<char>(toupper(ch));  // turn into uppercase
        newString.append(1,ucase);                    // append to back of result
    }

    return newString;
}

// ============================================================================
/** DO NOT MODIFY THE FUNCTIONS BELOW */

bool check(bool condition, const std::string& msg) {
    bool result = true;
    if (!condition) {
        std::cout << "\tAssertion failed: " << msg << std::endl;
        result = false;
    }
    return result;
}

void char_to_int_conversion_tests() {
    std::cout << "Checking Valid digit characters\n";
    check(char_to_int('0') == 0, "return value should be 0");
    check(char_to_int('1') == 1, "return value should be 1");
    check(char_to_int('9') == 9, "return value should be 9");

    std::cout << "Checking Invalid digit characters\n";
    check(char_to_int('Z') == 0, "return value should be 0");
    check(char_to_int('!') == 0, "return value should be 0");
    check(char_to_int('\n') == 0, "return value should be 0");
}

void int_to_char_conversion_tests() {
    std::cout << "Checking Valid integers\n";
    check(int_to_char(0) == '0', "return value should be '0'");
    check(int_to_char(1) == '1', "return value should be '1'");
    check(int_to_char(9) == '9', "return value should be '9'");
}

void reverse_string_tests() {
    std::cout << "Checking Normal strings\n";
    check(reverse_string("abc") == "cba", "returned string should be \"cba\"");
    check(reverse_string("A man a plan a canal Panama") == "amanaP lanac a nalp a nam A",
          "returned string should be \"amanaP lanac a nalp a nam A\"");

    std::cout << "Checking Edge cases\n";
    check(reverse_string("") == "", "returned string should be \"\"");
    check(reverse_string("a") == "a", "returned string should be \"a\"");
}

void to_uppercase_tests() {
    std::cout << "Checking Normal strings\n";
    check(to_uppercase("hello world") == "HELLO WORLD", "returned string should be \"HELLO WORLD\"");
    check(to_uppercase("TestString") == "TESTSTRING", "returned string should be \"TESTSTRING\"");

    std::cout << "Checking Strings with non-alphabetic characters\n";
    check(to_uppercase("12345") == "12345", "returned string should be \"12345\"");
    check(to_uppercase("Hello World! 123") == "HELLO WORLD! 123", "returned string should be \"HELLO WORLD! 123\"");

    std::cout << "Checking Edge cases\n";
    check(to_uppercase("") == "", "returned string should be \"\"");
    check(to_uppercase("A") == "A", "returned string should be \"A\"");
}

/* EOF */
