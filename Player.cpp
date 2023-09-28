//
// Created by Nathan Blanchard on 9/12/23.
//

#include <string>
#include "Player.h"
#include "PlayerSymbols.h"


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