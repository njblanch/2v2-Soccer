//
// Created by Nathan Blanchard on 9/10/23.
//

#ifndef M1OEP_NJBLANCH_PLAYER_H
#define M1OEP_NJBLANCH_PLAYER_H

#include <string>
#include <iostream>

using std::string, std::cout, std::endl;

class Player {
public:
    // Constructor
    Player(int teamNumber, int playerNumber);

    // Returns the player symbol generated based on fields teamNumber, playerNumber, and ballPossession
    string generatePlayerSymbol();

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
    virtual bool moveInput(std::vector<std::vector<bool>> occupiedSpaces);
    virtual bool shoot(int fieldWidth, int fieldHeight);

private:
    int teamNumber;
    int playerNumber;
    int xPosition;
    int yPosition;
    bool ballPossession;
};

#endif //M1OEP_NJBLANCH_PLAYER_H
