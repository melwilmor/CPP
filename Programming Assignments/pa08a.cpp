/// @brief This program simulates a futuristic race, where players will jump
/// through portals along a racetrack - first player to reach squuare 100 wins.

#include <iostream>
#include <string>

using namespace std;

// Global Constants
const int MAX_PLAYERS = 1000;           // Max number of players in any game
const int MAX_PORTALS = 100;            // Max number of portals in any game
const int MAX_ROLLS = 1000;             // Max number of dice rolls in a game
const int TRACK_SIZE = 101;             // Number of squares on the board
const int NO_PORTAL = -1;               // Sentinel value

// Function Prototypes
void process_all_games(int numGames);
void run_race(int numPlayers, int numRolls, int portalMap[], int rolls[]);
int apply_portals(int position, int portalMap[]);

int main() {
    int numGames;

    cin >> numGames;                    // Read total number of games to simulate

    process_all_games(numGames);        // Start processing all games

    return 0;
}

// Function definitions

/// @brief processes multiple race games
/// @param numGames - total number of games
void process_all_games(int numGames) {
    for (int game = 0; game < numGames; game++) {
        int numPlayers;
        int numPortals;
        int numRolls;

        // Read game setup values
        cin >> numPlayers >> numPortals >> numRolls;

        // Initialize the portal map
        int portalMap[TRACK_SIZE];
        for (int i = 0; i < TRACK_SIZE; i++) {
            portalMap[i] = NO_PORTAL;
        }

        // Read each portal and populate the portalMap
        for (int i = 0; i < numPortals; i++) {
            int from;
            int to;

            cin >> from >> to;
            portalMap[from] = to;
        }

        // Read all die rolls for the game
        int rolls[MAX_ROLLS];
        for (int i = 0; i < numRolls; i++) {
            cin >> rolls[i];
        }

        // Simulate race with the given data
        run_race(numPlayers, numRolls, portalMap, rolls);
    }
}

/// @brief Runs a single race simulation
/// @param numPlayers - number of players
/// @param numPortals - number of portals
/// @param numRolls - number of die rolls
/// @param portalMap - portal mappings from square to destination
/// @param rolls - list of die roll values
void run_race(int numPlayers, int numRolls, int portalMap[], int rolls[]) {
    int positions[MAX_PLAYERS];

    // Initialize each player to square 1
    for (int i = 0; i< numPlayers; i++) {
        positions[i] = 1;
    }

    bool gameOver = false;

    // Apply die rolls one-y-one while the game is running
    for (int i = 0; i < numRolls && !gameOver; i++) {
        // Determine whose turn it is
        int currentPlayer = i % numPlayers;

        // Only move if the roll is within the game paramaters (100 squares)
        if (positions[currentPlayer] + rolls[i] <= 100) {
            positions[currentPlayer] += rolls[i];
            positions[currentPlayer] = apply_portals(positions[currentPlayer],
            portalMap);

            // End game if a player has hit 100 and won
            if (positions[currentPlayer] == 100) {
                gameOver = true;
            }
        }
    }
    // Output final pole position
    for (int i = 0; i < numPlayers; i++) {
            cout << "Runner " << (i + 1) << " is at position " << positions[i]
            << "." << endl;
    }
}

/// @brief Applies portals until no portals are hit
/// @param position - current position of the player
/// @param portalMap - portal mappings
/// @return - final position after all portals are applied
int apply_portals(int position, int portalMap[]) {
    // Follow portal links until the position has no more portals
    while (portalMap[position] != NO_PORTAL) {
        position = portalMap[position];
    }
    return position;
}


