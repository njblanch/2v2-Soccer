//
// Created by Nathan Blanchard on 10/3/23.
//

#ifndef M2OEP_NJBLANCH_STRIKERPLAYER_H
#define M2OEP_NJBLANCH_STRIKERPLAYER_H

#include "Player.h"

using std::string;

class StrikerPlayer : public Player {
public:
    StrikerPlayer(int teamNumber, int playerNumber);


    bool shoot(int fieldWidth, int fieldHeight) override;
};

#endif //M2OEP_NJBLANCH_STRIKERPLAYER_H
