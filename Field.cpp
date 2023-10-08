//
// Created by Nathan Blanchard on 9/12/23.
//

#include <iostream>
#include "Field.h"
#include "Player.h"


/**************** Field class ****************/

// Default constructor
Field::Field() {
    // Initialize field vector
    // Default size - width: 20, height: 10
    width = 20;
    height = 10;
    fieldVector.resize(height, std::vector<Player*>(width, nullptr));
}

// Constructor to set field width and height
Field::Field(int width, int height) : width(width), height(height) {
    // Initialize field vector
    // Set size to specified size
    if (width < 10 || height < 7) {
        // Field too small, set to default values
        width = 20;
        height = 10;
    }
    fieldVector.resize(height, std::vector<Player *>(width, nullptr));
}

// Update player position to match position stored in player object
bool Field::setPlayerPos(Player* player) {
    int yPos;
    int xPos;
    bool found = false;
    for (yPos = 0; yPos < fieldVector.size(); ++yPos) {
        for (xPos = 0; xPos < fieldVector[yPos].size(); ++xPos) {
            if (fieldVector[yPos][xPos] == player) {
                fieldVector[yPos][xPos] = nullptr;
                fieldVector[player->getYPosition()][player->getXPosition()] = player;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    return found;
}

// Set player position to x and y, also call setters for position for player object
bool Field::setPlayerPos(Player* player, int x, int y) {
    // Update the player's position in the field vector
    if (x < width && x >= 0 && y < height && y >= 0) {
        if (!isSpaceOccupied(x, y)) {
            fieldVector[player->getYPosition()][player->getXPosition()] = nullptr;
            fieldVector[y][x] = player;
            player->setXPosition(x);
            player->setYPosition(y);
            return true;
        } else {
            return false;
        }
    }
    return false;
}

// Getters
int Field::getWidth() const {
    return width;
}

int Field::getHeight() const {
    return height;
}

// Returns a vector of booleans which is the same size as the field vector where
// true means a player is in a position and false means the position is empty
std::vector<std::vector<bool>> Field::getOccupiedSpaces() {
    std::vector<std::vector<bool>> occupiedSpaces;
    if (!fieldVector.empty()) {
        occupiedSpaces = std::vector<std::vector<bool>>(fieldVector.size(),std::vector<bool>(fieldVector[0].size(),false));
        for (int y = 0; y < fieldVector.size(); ++y) {
            for (int x = 0; x < fieldVector[0].size(); ++x) {
                if (isSpaceOccupied(x, y)) {
                    occupiedSpaces[y][x] = true;
                }
            }
        }
    }
    return occupiedSpaces;
}

// Check if a space is occupied by a player
bool Field::isSpaceOccupied(int x, int y) {
    if (fieldVector[y][x] == nullptr) {
        return false;
    }
    return true;
}

// Overload << operator for field
ostream& operator<<(ostream& outs, const Field& field) {
    // Top border for field
    outs << "   ";
    for (int i = 0; i < field.width * 3; ++i) {
        outs << "-";
    }
    outs << endl;

    for (int y = 0; y < field.height; ++y) {
        // Left goal
        if (y <= double(field.height - 1) / 2 + 1 && y >= double(field.height - 1) / 2 - 1) {
            outs << "| |";
        } else if (y + 1 <= double(field.height - 1) / 2 + 1 && y + 1 >= double(field.height - 1) / 2 - 1 ||
                   y - 1 <= double(field.height - 1) / 2 + 1 && y - 1 >= double(field.height - 1) / 2 - 1) {
            outs << " -|";
        } else {
            outs << "  |";
        }
        // Body of field
        for (int x = 0; x < field.width; ++x) {
            if (field.fieldVector[y][x] == nullptr) {
                if (y % 2 == 0) {
                    if (x % 2 == 0) {
                        outs << "███";
                    } else {
                        outs << "   ";
                    }
                } else {
                    if (x % 2 == 1) {
                        outs << "███";
                    } else {
                        outs << "   ";
                    }
                }
            } else {
                outs << field.fieldVector[y][x]->generatePlayerSymbol();
            }
        }
        // Right goal
        if (y <= double(field.height - 1) / 2 + 1 && y >= double(field.height - 1) / 2 - 1) {
            outs << "| |" << endl;
        } else if (y + 1 <= double(field.height - 1) / 2 + 1 && y + 1 >= double(field.height - 1) / 2 - 1 || y - 1 <= double(field.height - 1) / 2 + 1 && y - 1 >= double(field.height - 1) / 2 - 1) {
            outs << "|-" << endl;
        } else {
            outs << "|" << endl;
        }
    }

    // Bottom border for field
    outs << "   ";
    for (int i = 0; i < field.width * 3; ++i) {
        outs << "-";
    }
    outs << endl;

    return outs;
}
