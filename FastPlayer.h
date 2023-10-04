//
// Created by Nathan Blanchard on 10/3/23.
//

#ifndef M2OEP_NJBLANCH_FASTPLAYER_H
#define M2OEP_NJBLANCH_FASTPLAYER_H

#include "Player.h"

using std::ostream;

class FastPlayer : public Player {
    FastPlayer(int teamNumber, int playerNumber);

    string generatePlayerSymbol() override;

    bool move(Field& field) override;
    bool shoot() override;
};

#endif //M2OEP_NJBLANCH_FASTPLAYER_H
