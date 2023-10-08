//
// Created by Nathan Blanchard on 9/7/23.
//

#include <iostream>
#include "SoccerGame.h"

using namespace std;


int main() {
    srand(time(NULL));
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

    // Start the game
    game.startGame();

    // Main logic for the game
    while (!game.isGameOver()) {

        // Print the playing field
        cout << game.getField() << endl;

        // Execute the next turn
        game.nextTurn();
    }

    if (game.getTeam1Score() >= 3) {
        cout << "Team 1 Wins!!!" << endl;
    } else {
        cout << "Team 2 Wins!!!" << endl;
    }

    return 0;
}



