//
// Created by Nathan Blanchard on 10/3/23.
//

#include "StrikerPlayer.h"

StrikerPlayer::StrikerPlayer(int teamNumber, int playerNumber) : Player(teamNumber, playerNumber) {
}


bool StrikerPlayer::move(Field& field) {
    //cout << "Which direction would you like to move?\n(1) Up\n(2) Down\n(3) Left\n(4) Right" << endl;
    cout << "Which direction would you like to move?\n"
            "1   2   3\n"
            "  ↖ ↑ ↗  \n"
            "4 ← · → 5\n"
            "  ↙ ↓ ↘  \n"
            "6   7   8" << endl;
    int numChoices = 8;
    int directionChoice = getUserInput(numChoices);
    bool validMove;
    // Set player position based on direction choice
    if (directionChoice == 1) {
        validMove = field.setPlayerPos(this, getXPosition() - 1, getYPosition() - 1);
    } else if (directionChoice == 2) {
        validMove = field.setPlayerPos(this, getXPosition(), getYPosition() - 1);
    } else if (directionChoice == 3) {
        validMove = field.setPlayerPos(this, getXPosition() + 1, getYPosition() - 1);
    } else if (directionChoice == 4) {
        validMove = field.setPlayerPos(this, getXPosition() - 1, getYPosition());
    } else if (directionChoice == 5) {
        validMove = field.setPlayerPos(this, getXPosition() + 1, getYPosition());
    } else if (directionChoice == 6) {
        validMove = field.setPlayerPos(this, getXPosition() - 1, getYPosition() + 1);
    } else if (directionChoice == 7) {
        validMove = field.setPlayerPos(this, getXPosition(), getYPosition() + 1);
    } else if (directionChoice == 8) {
        validMove = field.setPlayerPos(this, getXPosition() + 1, getYPosition() + 1);
    }
    if (!validMove) {
        cout << "You can't move player " << getPlayerNumber() << " in that direction right now" << endl;
    }
    return validMove;
}

bool StrikerPlayer::shoot() {
    return false;
}