//
// Created by Nathan Blanchard on 9/10/23.
//

#ifndef M1OEP_NJBLANCH_SOCCERGAME_H
#define M1OEP_NJBLANCH_SOCCERGAME_H

#include "Field.h"
#include "Player.h"

class SoccerGame {
public:

    // Default constructor
    SoccerGame();

    void startGame(); // Start the game
    void arrangePlayers(int startingOffense); // Arrange the players on the field

    // Check if the game is over
    bool isGameOver();

    // Getters
    int getActiveTeam(); // Get the active team (1 or 2)
    int getOffense(); // Get which team is on offense (1 or 2)
    Field getField(); // Get the field object
    int getTeam1Score(); // Get the score for team 1
    int getTeam2Score(); // Get the score for team 2

    // Setters
    void setPlayer(int playerChoice); // Set the active player (1 or 2)

    // Game Actions
    void nextTurn();
    bool movePlayer(int directionChoice); // Move the selected player in a specified direction
    void passBall(); // Pass the ball
    bool shootBall(); // Shoot the ball
    bool canStealBall(); // Test if the ball can be stolen
    void switchActiveTeam(); // Swap between teams 1 and 2 being active

private:
    int getUserInput(int selectionMax);

    Player team1Player1, team1Player2, team2Player1, team2Player2; // Player objects
    Player* activePlayer; // Pointer to whatever player is active
    Field field; // Field object
    int activeTeam;
    int offense;
    int team1Score, team2Score;
    int remainingTurns;
};

#endif //M1OEP_NJBLANCH_SOCCERGAME_H
