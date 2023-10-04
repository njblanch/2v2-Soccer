//
// Created by Nathan Blanchard on 10/3/23.
//

#include "FastPlayer.h"


FastPlayer::FastPlayer(int teamNumber, int playerNumber) : Player(teamNumber, playerNumber) {
}

string FastPlayer::generatePlayerSymbol() {
    return std::string();
}

bool FastPlayer::move(Field& field) {
    //cout << "MOVE #1: Which direction would you like to move?\n(1) Up\n(2) Down\n(3) Left\n(4) Right" << endl;
    cout << "MOVE #1: Which direction would you like to move?\n"
            "    1    \n"
            "    ↑    \n"
            "2 ← · → 3\n"
            "    ↓    \n"
            "    4    " << endl;
    int numChoices = 4;
    int directionChoice = getUserInput(numChoices);
    bool validMove;
    // Set player position based on direction choice
    if (directionChoice == 1) {
        validMove = field.setPlayerPos(this, getXPosition(), getYPosition() - 1);
    } else if (directionChoice == 2) {
        validMove = field.setPlayerPos(this, getXPosition() - 1, getYPosition());
    } else if (directionChoice == 3) {
        validMove = field.setPlayerPos(this, getXPosition() + 1, getYPosition());
    } else {
        validMove = field.setPlayerPos(this, getXPosition(), getYPosition() + 1);
    }
    if (!validMove) {
        cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
        return false;
    }
    validMove = false;
    while (!validMove) {
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
            validMove = field.setPlayerPos(this, getXPosition(), getYPosition() - 1);
        } else if (directionChoice == 2) {
            validMove = field.setPlayerPos(this, getXPosition() - 1, getYPosition());
        } else if (directionChoice == 3) {
            validMove = field.setPlayerPos(this, getXPosition() + 1, getYPosition());
        } else {
            validMove = field.setPlayerPos(this, getXPosition(), getYPosition() + 1);
        }
        if (!validMove) {
            cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
            return false;
        }
    }
}

bool FastPlayer::shoot() {
    return false;
}

