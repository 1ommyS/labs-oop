#ifndef LAB5_DISTANCECALCULATOR_H
#define LAB5_DISTANCECALCULATOR_H

#include "../include/mobs/NPC.h"
#include "cmath"

using namespace Mobs;

class DistanceCalculator {
public:
    static double CalculateDistance(NPC *pNpc, NPC *pNpc1) {
        return sqrt(pow(pNpc->position.GetX() - pNpc1->position.GetX(), 2) +
                    pow(pNpc->position.GetY() - pNpc1->position.GetY(), 2));
    }
};


#endif //LAB5_DISTANCECALCULATOR_H
