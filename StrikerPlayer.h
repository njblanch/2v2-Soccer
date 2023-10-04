//
// Created by Nathan Blanchard on 10/3/23.
//

#ifndef M2OEP_NJBLANCH_STRIKERPLAYER_H
#define M2OEP_NJBLANCH_STRIKERPLAYER_H

#include "Player.h"
#include "Field.h"

using std::string;

class StrikerPlayer : public Player {
    StrikerPlayer(int teamNumber, int playerNumber);

    string generatePlayerSymbol() override;

    bool move(Field& field) override;
    bool shoot() override;
};

#endif //M2OEP_NJBLANCH_STRIKERPLAYER_H
