//
// Created by Nathan Blanchard on 9/12/23.
//

#ifndef M1OEP_NJBLANCH_FIELD_H
#define M1OEP_NJBLANCH_FIELD_H

#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

using std::endl, std::ostream;

class Field {
public:

    Field(); // Default constructor

    Field(int width, int height); // Constructor to set width and height of field

    // Setters
    bool setPlayerPos(Player* player); // Update player position
    bool setPlayerPos(Player* player, int x, int y); // Set player position with specified x and y

    // Getters
    int getWidth() const;
    int getHeight() const;
    std::vector<std::vector<bool>> getOccupiedSpaces();

    bool isSpaceOccupied(int x, int y); // Check if a space is occupied by a player

    // Overload << operator for field
    friend ostream& operator<<(ostream& outs, const Field& field);

private:
    int width;
    int height;
    std::vector<std::vector<Player*>> fieldVector;
};

#endif //M1OEP_NJBLANCH_FIELD_H
