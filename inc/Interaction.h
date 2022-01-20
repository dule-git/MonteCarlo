//
// Created by dusan on 19-Jan-22.
//

#ifndef MONTECARLO_INTERACTION_H
#define MONTECARLO_INTERACTION_H

namespace photon
{
    class Photon;
}

class Interaction
{
public:
    typedef enum
    {
        COHERENT_RACE = 0, NON_COHERENT_RACE, PHOTOELECTRIC_ABSORPTION
    }InteractionType;
public:
    virtual void Interact(photon::Photon& photon) = 0;
    virtual InteractionType GetInteractionType() = 0;
    
    static Interaction* GetNewInteractionRandom();
};


#endif //MONTECARLO_INTERACTION_H
