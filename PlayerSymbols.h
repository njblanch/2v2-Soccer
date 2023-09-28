//
// Created by Nathan Blanchard on 9/17/23.
//

#include <string>

using std::string;

#ifndef M1OEP_NJBLANCH_PLAYERSYMBOLS_H
#define M1OEP_NJBLANCH_PLAYERSYMBOLS_H

// Enum to represent the fixed set of symbols that the players can have
enum PlayerSymbol {
    player1Team1,
    player2Team1,
    player1Team2,
    player2Team2,
    player1Team1Ball,
    player2Team1Ball,
    player1Team2Ball,
    player2Team2Ball,
};

// Function to get the string associated with the PlayerSymbol enums
string symbolString(PlayerSymbol symbol) {
    switch(symbol) {
        case player1Team1:
            return "[𖨆]";
        case player1Team1Ball:
            return "𖨆⚽";
        case player2Team1:
            return "[𖠋]";
        case player2Team1Ball:
            return "𖠋⚽";
        case player1Team2:
            return "{𖨆}";
        case player1Team2Ball:
            return "⚽𖨆";
        case player2Team2:
            return "{𖠋}";
        case player2Team2Ball:
            return "⚽𖠋";
    }
}


#endif //M1OEP_NJBLANCH_PLAYERSYMBOLS_H
