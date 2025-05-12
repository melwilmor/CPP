/// @brief This program uses 2D arrays to process data to determine the likely
/// next location for astronomers to look for new, undiscovered planets.

#include <iostream>
#include <string>

using namespace std;

// Global Constants
const size_t MAX = 9;           //< Maximum dimension of a grid.

// Function Prototypes
void swap_rows(int grid[][MAX], size_t a, size_t b, size_t size);
void swap_columns(int grid[][MAX], size_t a, size_t b, size_t size);
void increment_grid(int grid[][MAX], size_t size);
void decrement_grid(int grid[][MAX], size_t size);
void transpose_grid(int grid[][MAX], size_t size);
void print_grid(const int grid[][MAX], size_t size);

int main() {
    //****** Declare Variables *********
    int grid[MAX][MAX];         // 2D array to hold sky data
    size_t size;                // Dimension of the grid
    size_t operations;          // Number of operations to apply
    size_t caseNumber = 1;      // Case counter

    // ***** Input *********************
    cin >> size;                // Read size of the grid

    // ***** Process *******************
    while (size != 0) {
        // Read grid values as strings of digits
        for (size_t i = 0; i < size; i++) {
            string row;
            cin >> row;
            for (size_t j = 0; j < size; j++) {
                grid[i][j] = row.at(j) - '0';
            }
        }

        cin >> operations;

        for (size_t i = 0; i < operations; i++) {
            string cmd;
            cin >> cmd;

            if (cmd == "row") {
                size_t a;
                size_t b;
                cin >> a >> b;
                swap_rows(grid, a - 1, b - 1, size);
            }
            else if (cmd == "col") {
                size_t a;
                size_t b;
                cin >> a >> b;
                swap_columns(grid, a - 1, b - 1, size);
            }
            else if (cmd == "inc") {
                increment_grid(grid, size);
            }
            else if (cmd == "dec") {
                decrement_grid(grid, size);
            }
            else if (cmd == "transpose") {
                transpose_grid(grid, size);
            }
        }

        // ***** Output ********************
        cout << "Case #" << caseNumber << '\n';
        print_grid(grid, size);

        caseNumber++;
        cin >> size;
        if (size != 0) {
            cout << '\n';
        }
    }

    return 0;
}

// Function Definitions

/// @brief Swap two rows in a given grid.
/// @param [in,out] grid The grid in which rows are to be swapped.
/// @param a The first row to be swapped (zero-based index).
/// @param b The second row to be swapped (zero-based index).
/// @param size The size of the grid (number of rows/columns).
void swap_rows(int grid[][MAX], size_t a, size_t b, size_t size)
{
    for (size_t j = 0; j < size; j++) {
        int temp = grid[a][j];
        grid[a][j] = grid[b][j];
        grid[b][j] = temp;
    }
}

/// @brief Swap two columns in a given grid.
/// @param [in,out] grid The grid in which columns are to be swapped.
/// @param a The first column to be swapped (zero-based index).
/// @param b The second column to be swapped (zero-based index).
/// @param size The size of the grid (number of rows/columns).
void swap_columns(int grid[][MAX], size_t a, size_t b, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        int temp = grid[i][a];
        grid[i][a] = grid[i][b];
        grid[i][b] = temp;
    }
}

/// @brief Increment each element in the grid by 1, wrapping around to 0 at 10.
/// @param [in,out] grid The grid to be incremented.
/// @param size The size of the grid (number of rows/columns).
void increment_grid(int grid[][MAX], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            grid[i][j] = (grid[i][j] + 1) % 10;
        }
    }
}

/// @brief Decrement each element in the grid by 1, wrapping around to 9 at -1.
/// @param [in,out] grid The grid to be decremented.
/// @param size The size of the grid (number of rows/columns).
void decrement_grid(int grid[][MAX], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = 9;
            }
            else {
                grid [i][j]--;
            }
        }
    }
}

/// @brief Transpose the given grid.
/// @param [in,out] grid The grid to be transposed.
/// @param size The size of the grid(number of rows/columns).
void transpose_grid(int grid[][MAX], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            int temp = grid[i][j];
            grid[i][j] = grid[j][i];
            grid[j][i] = temp;
        }
    }
}

/// @brief Prints the grid to standard output
/// @param grid - the 2D array
/// @param size - Grid dimension
void print_grid(const int grid[][MAX], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
