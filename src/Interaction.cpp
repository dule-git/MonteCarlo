//
// Created by dusan on 19-Jan-22.
//

#include "Interaction.h"
#include "CoherentRace.h"
#include "stdinc.h"

Interaction *Interaction::GetNewInteractionRandom()
{
    double randNum = random();
    if (randNum <= 1.0)
    {
        return new CoherentRace();
    }
    else
    {
        return new CoherentRace();
    }
}
