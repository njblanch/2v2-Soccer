//
// Created by Nathan Blanchard on 10/3/23.
//

#include <vector>
#include "FastPlayer.h"


FastPlayer::FastPlayer(int teamNumber, int playerNumber) : Player(teamNumber, playerNumber) {
}

bool FastPlayer::moveInput(std::vector<std::vector<bool>> occupiedSpaces) {
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
    if (newY < occupiedSpaces.size() && newX < occupiedSpaces[newY].size() && newX >= 0 && newY >= 0) {
        validMove = !occupiedSpaces[newY][newX];
    }
    if (!validMove) {
        cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
        return validMove;
    }
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

