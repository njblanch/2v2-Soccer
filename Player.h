//
// Created by Nathan Blanchard on 9/10/23.
//

#ifndef M1OEP_NJBLANCH_PLAYER_H
#define M1OEP_NJBLANCH_PLAYER_H

#include "Field.h"
#include <string>
#include <iostream>

using std::string, std::cout, std::endl;

class Player {
public:
    // Constructor
    Player(int teamNumber, int playerNumber);

    // Returns the player symbol generated based on fields teamNumber, playerNumber, and ballPossession
    virtual string generatePlayerSymbol() = 0;

    // Getters
    int getTeamNumber() const;
    int getPlayerNumber() const;
    int getXPosition();
    int getYPosition();
    bool hasBall();

    // Setters
    void setXPosition(int x);
    void setYPosition(int y);
    void setHasBall(bool hasBall);

    // Player actions
    virtual bool move(Field& field) = 0;
    virtual bool shoot() = 0;

private:
    int teamNumber;
    int playerNumber;
    int xPosition;
    int yPosition;
    bool ballPossession;
};

#endif //M1OEP_NJBLANCH_PLAYER_H
