//
// Created by Nathan Blanchard on 10/3/23.
//

#include <vector>
#include "FastPlayer.h"
#include "UserInput.h"


FastPlayer::FastPlayer(int teamNumber, int playerNumber) : Player(teamNumber, playerNumber) {
}

// Function moveInput takes in a vector of spaces that is the same size as the field.
// This will then prompt the user for where they would like to move
// Validates input and returns true if the user gives a valid move and false otherwise
// Overrides moveInput function from Player to allow for two moves in one turn
bool FastPlayer::moveInput(std::vector<std::vector<bool>> occupiedSpaces) {
    // Prompt user for direction, validate input
    cout << "MOVE #1: Which direction would you like to move?\n"
            "    1    \n"
            "    ↑    \n"
            "2 ← · → 3\n"
            "    ↓    \n"
            "    4    " << endl;
    int numChoices = 4;
    int directionChoice = getUserInput(numChoices);
    bool validMove = false;
    int newY;
    int newX;
    // Set player position based on direction choice
    if (directionChoice == 1) {
        newY = getYPosition() - 1;
        newX = getXPosition();
    } else if (directionChoice == 2) {
        newY = getYPosition();
        newX = getXPosition() - 1;
    } else if (directionChoice == 3) {
        newY = getYPosition();
        newX = getXPosition() + 1;
    } else {
        newY = getYPosition() + 1;
        newX = getXPosition();
    }
    // Check if move is valid
    if (newY < occupiedSpaces.size() && newX < occupiedSpaces[newY].size() && newX >= 0 && newY >= 0) {
        validMove = !occupiedSpaces[newY][newX];
    }
    if (!validMove) {
        cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
        return validMove;
    }
    // Ask user for next move, validate input
    cout << "MOVE #2: Which direction would you like to move?\n"
            "    1    \n"
            "    ↑    \n"
            "2 ← · → 3\n"
            "    ↓    \n"
            "    4    " << endl;
    numChoices = 4;
    directionChoice = getUserInput(numChoices);
    // Set player position based on direction choice
    if (directionChoice == 1) {
        newY = newY - 1;
    } else if (directionChoice == 2) {
        newX = newX - 1;
    } else if (directionChoice == 3) {
        newX = newX + 1;
    } else {
        newY = newY + 1;
    }
    // Check if move is valid
    if (newY < occupiedSpaces.size() && newX < occupiedSpaces[newY].size() && newX >= 0 && newY >= 0) {
        validMove = !occupiedSpaces[newY][newX];
    }
    if (!validMove) {
        cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
    } else {
        setYPosition(newY);
        setXPosition(newX);
    }
    return validMove;
}

