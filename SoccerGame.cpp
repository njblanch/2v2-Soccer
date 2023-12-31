//
// Created by Nathan Blanchard on 9/12/23.
//

#include <cmath>
#include <iostream>
#include "SoccerGame.h"

using std::cout, std::endl;


/**************** SoccerGame class ****************/

// Default constructor
SoccerGame::SoccerGame() :
    // Initialize player objects
    team1Player1(1, 1),
    team1Player2(1, 2),
    team2Player1(2, 1),
    team2Player2(2, 2),
    // Initialize playing field
    field(20, 10),
    // Set the active team to 1
    activeTeam(1),
    // Set the active player to team1Player1
    activePlayer(&team1Player1),
    // Team 1 starts on offense
    offense(1),
    team1Score(0),
    team2Score(0),
    remainingTurns(8)
{}

// Start the game
void SoccerGame::startGame() {
    team1Score = 0;
    team2Score = 0;
    arrangePlayers(1);
}

// Arrange the players on the field for the start of play
void SoccerGame::arrangePlayers(int startingOffense) {
    if (startingOffense == 1) {
        // Set player positions and ball possession for if team 1 is on offense
        field.setPlayerPos(&team1Player1, field.getWidth() / 2 - 1, field.getHeight() / 2 + 1);
        field.setPlayerPos(&team1Player2, field.getWidth() / 2 - 2, field.getHeight() / 2 - 1);
        field.setPlayerPos(&team2Player1, field.getWidth() / 2 + 4, field.getHeight() / 2 - 3);
        field.setPlayerPos(&team2Player2, field.getWidth() / 2 + 3, field.getHeight() / 2 + 2);
        team1Player1.setHasBall(true);
        team1Player2.setHasBall(false);
        team2Player1.setHasBall(false);
        team2Player2.setHasBall(false);
        offense = 1;
    } else {
        // Set player positions and ball possession for if team 2 is on offense
        field.setPlayerPos(&team1Player1, field.getWidth() / 2 - 4, field.getHeight() / 2 - 3);
        field.setPlayerPos(&team1Player2, field.getWidth() / 2 - 3, field.getHeight() / 2 + 2);
        field.setPlayerPos(&team2Player1, field.getWidth() / 2 + 1, field.getHeight() / 2 + 1);
        field.setPlayerPos(&team2Player2, field.getWidth() / 2 + 2, field.getHeight() / 2 - 1);
        team1Player1.setHasBall(false);
        team1Player2.setHasBall(false);
        team2Player1.setHasBall(true);
        team2Player2.setHasBall(false);
        offense = 2;
    }
}

// Check if the game is over
bool SoccerGame::isGameOver() {
    if (team1Score >= 3 || team2Score >= 3) {
        return true;
    }
    return false;
}

// Get the active team (1 or 2)
int SoccerGame::getActiveTeam() {
    return activeTeam;
}

// Get which team is on offense (1 or 2)
int SoccerGame::getOffense() {
    return offense;
}

// Get the field object
Field SoccerGame::getField() {
    return field;
}

// Get the score for team 1
int SoccerGame::getTeam1Score() {
    return team1Score;
}

// Get the score for team 2
int SoccerGame::getTeam2Score() {
    return team2Score;
}

// Set the active player (1 or 2)
void SoccerGame::setPlayer(int playerChoice) {
    if (playerChoice == 1 && activeTeam == 1) {
        activePlayer = &team1Player1;
    } else if (playerChoice == 2 && activeTeam == 1) {
        activePlayer = &team1Player2;
    } else if (playerChoice == 1 && activeTeam == 2) {
        activePlayer = &team2Player1;
    } else {
        activePlayer = &team2Player2;
    }
}

// This is where a lot of the gameplay logic is stored
// This function executes the next turn at any given point in the game
void SoccerGame::nextTurn() {
    int numChoices;
    int playerChoice;
    int actionChoice;
    int directionChoice;
    bool validPlay;
    bool stealBall;
    bool shotAttempt;
    bool successfulShot;

    if (activeTeam == offense) {
        --remainingTurns;
    }
    shotAttempt = false;
    successfulShot = false;

    cout << "Team " << activeTeam << " is up" << endl;
    validPlay = false;
    while (!validPlay) {
        if (offense == activeTeam) {
            cout << remainingTurns << " TURNS REMAINING" << endl;
            cout << "Would you like to...\n(1) Move\n(2) Pass\n(3) Shoot" << endl;
            numChoices = 3;
            actionChoice = getUserInput(numChoices);
            if (actionChoice == 1) {
                while (!validPlay) {
                    cout << "Which player would you like to move? 𖨆 or 𖠋 (1 or 2)?" << endl;
                    numChoices = 2;
                    playerChoice = getUserInput(numChoices);
                    setPlayer(playerChoice);
                    validPlay = activePlayer->moveInput(field.getOccupiedSpaces());
                    if (validPlay) {
                        field.setPlayerPos(activePlayer);
                    }
                }
            } else if (actionChoice == 2) {
                passBall();
                cout << "Team " << activeTeam << " passed the ball" << endl;
                validPlay = true;
            } else {
                shotAttempt = true;
                if (team1Player1.hasBall()) {
                    activePlayer = &team1Player1;
                } else if (team1Player2.hasBall()) {
                    activePlayer = &team1Player2;
                } else if (team2Player1.hasBall()) {
                    activePlayer = &team2Player1;
                } else {
                    activePlayer = &team2Player2;
                }
                successfulShot = activePlayer->shoot(field.getWidth(), field.getHeight());
                if (successfulShot) {
                    if (offense == 1) {
                        ++team1Score;
                    } else {
                        ++team2Score;
                    }
                }
                validPlay = true;
            }
        } else {
            cout << "Which player would you like to move? 𖨆 or 𖠋 (1 or 2)?" << endl;
            numChoices = 2;
            playerChoice = getUserInput(numChoices);
            setPlayer(playerChoice);
            validPlay = activePlayer->moveInput(field.getOccupiedSpaces());
            if (validPlay) {
                field.setPlayerPos(activePlayer);
            }
        }
    }
    stealBall = canStealBall();
    if (stealBall) {
        cout << "Team " << activeTeam << " stole the ball!" << endl;
        arrangePlayers(offense == 1 ? 2 : 1);
        offense = getOffense();
        if (offense != activeTeam) {
            switchActiveTeam();
        }
        cout << "Team " << activeTeam << " now has the ball" << endl;
        cout << "The score remains at " << team1Score << " - " << team2Score << endl;
        remainingTurns = 8;
    } else if (successfulShot) {
        cout << "Team " << activeTeam << " scored!" << endl;
        arrangePlayers(offense == 1 ? 2 : 1);
        switchActiveTeam();
        if (!isGameOver()) {
            cout << "Team " << activeTeam << " now has the ball" << endl;
        }
        cout << "The score is now " << team1Score << " - " << team2Score << endl;
        remainingTurns = 8;
    } else if (shotAttempt) {
        cout << "Team " << activeTeam << " tried to shoot but missed!" << endl;
        arrangePlayers(offense == 1 ? 2 : 1);
        switchActiveTeam();
        cout << "Team " << activeTeam << " now has the ball" << endl;
        cout << "The score remains at " << team1Score << " - " << team2Score << endl;
        remainingTurns = 8;
    } else if (remainingTurns <= 0) {
        cout << "Team " << activeTeam << " ran out of moves" << endl;
        arrangePlayers(offense == 1 ? 2 : 1);
        switchActiveTeam();
        cout << "Team " << activeTeam << " now has the ball" << endl;
        cout << "The score remains at " << team1Score << " - " << team2Score << endl;
        remainingTurns = 8;
    } else {
        switchActiveTeam();
    }
}

// Pass the ball
void SoccerGame::passBall() {
    // Set active player
    if (team1Player1.hasBall()) {
        activePlayer = &team1Player1;
    } else if (team1Player2.hasBall()) {
        activePlayer = &team1Player2;
    } else if (team2Player1.hasBall()) {
        activePlayer = &team2Player1;
    } else {
        activePlayer = &team2Player2;
    }
    // Swap which player has the ball
    if (activeTeam == 1) {
        if (activePlayer == &team1Player1) {
            team1Player1.setHasBall(false);
            team1Player2.setHasBall(true);
        } else {
            team1Player2.setHasBall(false);
            team1Player1.setHasBall(true);
        }
    } else {
        if (activePlayer == &team2Player1) {
            team2Player1.setHasBall(false);
            team2Player2.setHasBall(true);
        } else {
            team2Player1.setHasBall(true);
            team2Player2.setHasBall(false);
        }
    }
}

// Try to steal the ball
bool SoccerGame::canStealBall() {
    // Each of these tests to see if there is an opponent within 1 cardinal space of the player with the ball
    if (offense == 1) {
        if (team1Player1.hasBall()) {
            if (abs(team1Player1.getXPosition() - team2Player1.getXPosition()) + abs(team1Player1.getYPosition() - team2Player1.getYPosition()) <= 1) {
                return true;
            } else if (abs(team1Player1.getXPosition() - team2Player2.getXPosition()) + abs(team1Player1.getYPosition() - team2Player2.getYPosition()) <= 1) {
                return true;
            }
        } else {
            if (abs(team1Player2.getXPosition() - team2Player1.getXPosition()) + abs(team1Player2.getYPosition() - team2Player1.getYPosition()) <= 1) {
                return true;
            } else if (abs(team1Player2.getXPosition() - team2Player2.getXPosition()) + abs(team1Player2.getYPosition() - team2Player2.getYPosition()) <= 1) {
                return true;
            }
        }
    } else {
        if (team2Player1.hasBall()) {
            if (abs(team2Player1.getXPosition() - team1Player1.getXPosition()) + abs(team2Player1.getYPosition() - team1Player1.getYPosition()) <= 1) {
                return true;
            } else if (abs(team2Player1.getXPosition() - team1Player2.getXPosition()) + abs(team2Player1.getYPosition() - team1Player2.getYPosition()) <= 1) {
                return true;
            }
        } else {
            if (abs(team2Player2.getXPosition() - team1Player1.getXPosition()) + abs(team2Player2.getYPosition() - team1Player1.getYPosition()) <= 1) {
                return true;
            } else if (abs(team2Player2.getXPosition() - team1Player2.getXPosition()) + abs(team2Player2.getYPosition() - team1Player2.getYPosition()) <= 1) {
                return true;
            }
        }
    }
    return false;
}

// Switch the active team
void SoccerGame::switchActiveTeam() {
    activeTeam = activeTeam == 1 ? 2 : 1;
}

