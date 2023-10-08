//
// Created by Nathan Blanchard on 10/3/23.
//

#include <cmath>
#include <iostream>
#include "StrikerPlayer.h"

using std::cout, std::endl;

StrikerPlayer::StrikerPlayer(int teamNumber, int playerNumber) : Player(teamNumber, playerNumber) {
}

bool StrikerPlayer::shoot(int fieldWidth, int fieldHeight) {
    bool goal;
    double distance;
    // Distance stat for how far the player is from the goal (actually distance^2 so that scoring chance drops off faster)
    if (getTeamNumber() == 1) {
        distance = pow(double(fieldWidth - getXPosition()), 2) + pow(double(fieldHeight / 2) - getYPosition(), 2);
    } else {
        distance = pow(double(getXPosition()), 2) + pow(double(fieldHeight / 2) - getYPosition(), 2);
    }
    // Little calculation to decide if the player scores
    // StrikerPlayer always has at least a 25% chance of scoring from anywhere on the field
    // If chance is already > 0, add 25% to the scoring chance
    double chance = 100 - distance;
    if (chance < 0) {
        chance = 25;
    } else {
        chance += 25;
    }
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