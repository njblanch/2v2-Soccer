//
// Created by Nathan Blanchard on 9/7/23.
//

#include <iostream>
#include <sstream>
#include "SoccerGame.h"

using namespace std;

// Function gets and validates user input for an integer from 1 to selectionMax
int getUserInput(int selectionMax) {
    string input;
    int num;
    stringstream ss;
    getline(cin, input);
    // Check if input is empty
    if (input.length() == 0) {
        cout << "No input" << endl;
        cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
        ss.clear();
        return getUserInput(selectionMax);
    }
    // Make sure all characters are numeric
    for (char c : input) {
        if (!isnumber(c)) {
            cout << "Invalid input" << endl;
            cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
            return getUserInput(selectionMax);
        }
    }
    // Try to store input in num as int, check to make sure that it is within the desired range
    ss << input;
    if (!(ss >> num) || num > selectionMax || num <= 0) {
        cout << "Invalid input" << endl;
        cout << "Enter a number from 1 to " << selectionMax << "..." << endl;
        ss.clear();
        return getUserInput(selectionMax);
    }
    return num;
}

int main() {
    // Print out some info about the game
    cout << "Welcome to 2v2 Soccer!" << endl;
    cout << "Offense:" << endl;
    cout << " - On offense you can move one player twice, pass, or shoot" << endl;
    cout << " - The closer you are to the goal, the better chance you have of scoring" << endl;
    cout << " - Be fast! You only have 7 turns to score before you lose the ball to the opponent!" << endl;
    cout << "Defense:" << endl;
    cout << " - On defense you can move one player once" << endl;
    cout << " - Get within 1 cardinal space of the player with the ball to steal it" << endl;
    cout << "First team to 3 goals wins!" << endl << endl;
    cout << "[𖨆] = team 1" << endl;
    cout << "{𖠋} = team 2" << endl;

    // Create some variables and objects that we will need
    SoccerGame game;
    int activeTeam;
    int offense;
    int numChoices;
    int playerChoice;
    int actionChoice;
    int directionChoice;
    bool validPlay;
    bool stealBall;
    bool shotAttempt;
    bool successfulShot;
    int remainingTurns = 8;

    // Start the game
    game.startGame();

    // Main logic for the game
    while (!game.isGameOver()) {

        // Print the playing field
        cout << game.getField() << endl;

        // Get our active team and offense
        activeTeam = game.getActiveTeam();
        offense = game.getOffense();
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
                        game.setPlayer(playerChoice);
                        cout << "MOVE #1: Which direction would you like to move?\n(1) Up\n(2) Down\n(3) Left\n(4) Right" << endl;
                        numChoices = 4;
                        actionChoice = getUserInput(numChoices);
                        validPlay = game.movePlayer(actionChoice);
                        if (!validPlay) {
                            cout << "You can't move player " << playerChoice << " in that direction right now" << endl;
                        }
                    }
                    if (!game.canStealBall()) {
                        validPlay = false;
                    }
                    cout << game.getField() << endl;
                    while (!validPlay) {
                        cout << "MOVE #2: Which direction would you like to move?\n(1) Up\n(2) Down\n(3) Left\n(4) Right" << endl;
                        numChoices = 4;
                        actionChoice = getUserInput(numChoices);
                        validPlay = game.movePlayer(actionChoice);
                        if (!validPlay) {
                            cout << "You can't move player " << playerChoice << " in that direction right now" << endl;
                        }
                    }
                } else if (actionChoice == 2) {
                    game.passBall();
                    cout << "Team " << game.getActiveTeam() << " passed the ball" << endl;
                    validPlay = true;
                } else {
                    shotAttempt = true;
                    successfulShot = game.shootBall();
                    validPlay = true;
                }
            } else {
                cout << "Which player would you like to move? 𖨆 or 𖠋 (1 or 2)?" << endl;
                numChoices = 2;
                playerChoice = getUserInput(numChoices);
                game.setPlayer(playerChoice);
                cout << "Which direction would you like to move?\n(1) Up\n(2) Down\n(3) Left\n(4) Right" << endl;
                numChoices = 4;
                directionChoice = getUserInput(numChoices);
                validPlay = game.movePlayer(directionChoice);
                if (!validPlay) {
                    cout << "You can't move player " << playerChoice << " in that direction right now" << endl;
                }
            }
        }
        stealBall = game.canStealBall();
        if (stealBall) {
            cout << "Team " << game.getActiveTeam() << " stole the ball!" << endl;
            game.arrangePlayers(offense == 1 ? 2 : 1);
            offense = game.getOffense();
            if (offense != activeTeam) {
                game.switchActiveTeam();
            }
            cout << "Team " << game.getActiveTeam() << " now has the ball" << endl;
            cout << "The score remains at " << game.getTeam1Score() << " - " << game.getTeam2Score() << endl;
            remainingTurns = 8;
        } else if (successfulShot) {
            cout << "Team " << game.getActiveTeam() << " scored!" << endl;
            game.arrangePlayers(offense == 1 ? 2 : 1);
            game.switchActiveTeam();
            if (!game.isGameOver()) {
                cout << "Team " << game.getActiveTeam() << " now has the ball" << endl;
            }
            cout << "The score is now " << game.getTeam1Score() << " - " << game.getTeam2Score() << endl;
            remainingTurns = 8;
        } else if (shotAttempt) {
            cout << "Team " << game.getActiveTeam() << " tried to shoot but missed!" << endl;
            game.arrangePlayers(offense == 1 ? 2 : 1);
            game.switchActiveTeam();
            cout << "Team " << game.getActiveTeam() << " now has the ball" << endl;
            cout << "The score remains at " << game.getTeam1Score() << " - " << game.getTeam2Score() << endl;
            remainingTurns = 8;
        } else if (remainingTurns <= 0) {
            cout << "Team " << game.getActiveTeam() << " ran out of moves" << endl;
            game.arrangePlayers(offense == 1 ? 2 : 1);
            game.switchActiveTeam();
            cout << "Team " << game.getActiveTeam() << " now has the ball" << endl;
            cout << "The score remains at " << game.getTeam1Score() << " - " << game.getTeam2Score() << endl;
            remainingTurns = 8;
        } else {
            game.switchActiveTeam();
        }

    }

    if (game.getTeam1Score() >= 3) {
        cout << "Team 1 Wins!!!" << endl;
    } else {
        cout << "Team 2 Wins!!!" << endl;
    }

    return 0;
}



