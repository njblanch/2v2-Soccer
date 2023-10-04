//
// Created by Nathan Blanchard on 9/12/23.
//

#include <cmath>
#include <vector>
#include "Player.h"
#include "PlayerSymbols.h"
#include "UserInput.h"



/**************** Player class ****************/

// Constructor
Player::Player(int teamNum, int playerNum) {
    teamNumber = teamNum;
    playerNumber = playerNum;
    xPosition = 0;
    yPosition = 0;
    ballPossession = false;
}

// Getters
int Player::getTeamNumber() const {
    return teamNumber;
}

int Player::getPlayerNumber() const {
    return playerNumber;
}

int Player::getXPosition() {
    return xPosition;
}

int Player::getYPosition() {
    return yPosition;
}

bool Player::hasBall() {
    return ballPossession;
}

// Returns the player symbol generated based on fields teamNumber, playerNumber, and ballPossession
string Player::generatePlayerSymbol() {
    if (teamNumber == 1 && playerNumber == 1) {
        if (ballPossession) {
            return symbolString(player1Team1Ball);
        }
        return symbolString(player1Team1);
    } else if (teamNumber == 1 && playerNumber == 2) {
        if (ballPossession) {
            return symbolString(player2Team1Ball);
        }
        return symbolString(player2Team1);
    } else if (teamNumber == 2 && playerNumber == 1) {
        if (ballPossession) {
            return symbolString(player1Team2Ball);
        }
        return symbolString(player1Team2);
    } else {
        if (ballPossession) {
            return symbolString(player2Team2Ball);
        }
        return symbolString(player2Team2);
    }
}

// Setters
void Player::setXPosition(int x) {
    xPosition = x;
}

void Player::setYPosition(int y) {
    yPosition = y;
}

void Player::setHasBall(bool hasBall) {
    ballPossession = hasBall;
}

bool Player::moveInput(std::vector<std::vector<bool>> occupiedSpaces) {
    cout << "Which direction would you like to move?\n"
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
        newY = yPosition - 1;
        newX = xPosition;
    } else if (directionChoice == 2) {
        newY = yPosition;
        newX = xPosition - 1;
    } else if (directionChoice == 3) {
        newY = yPosition;
        newX = xPosition + 1;
    } else {
        newY = yPosition + 1;
        newX = xPosition;
    }
    if (newY < occupiedSpaces.size() && newX < occupiedSpaces[newY].size() && newX >= 0 && newY >= 0) {
        validMove = !occupiedSpaces[newY][newX];
    }
    if (!validMove) {
        cout << "You can't move player " << playerNumber << " in that direction right now" << endl;
    } else {
        yPosition = newY;
        xPosition = newX;
    }
    return validMove;
}

bool Player::shoot(int fieldWidth, int fieldHeight) {
    bool goal;
    double distance;
    // Distance stat for how far the player is from the goal (actually distance^2 so that scoring chance drops off faster)
    if (teamNumber == 1) {
        distance = pow(double(fieldWidth - xPosition), 2) + pow(double(fieldHeight / 2) - yPosition, 2);
    } else {
        distance = pow(double(xPosition), 2) + pow(double(fieldHeight / 2) - yPosition, 2);
    }
    // Little calculation to decide if the player scores
    double chance = 100 - distance;
    if (chance > 0) {
        if ((rand() % 100 + 1) > chance) {
            goal = false;
        } else {
            goal = true;
        }
    } else {
        goal = false;
    }
    return goal;
}