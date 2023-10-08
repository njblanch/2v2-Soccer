//
// Created by Nathan Blanchard on 10/3/23.
//

#ifndef M2OEP_NJBLANCH_FASTPLAYER_H
#define M2OEP_NJBLANCH_FASTPLAYER_H

#include "Player.h"
#include "UserInput.h"

using std::ostream;

class FastPlayer : public Player {
public:
    FastPlayer(int teamNumber, int playerNumber);

    bool moveInput(std::vector<std::vector<bool>> occupiedSpaces) override;
};

#endif //M2OEP_NJBLANCH_FASTPLAYER_H
