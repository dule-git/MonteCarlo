//
// Created by dusan on 19-Jan-22.
//

#ifndef MONTECARLO_COHERENTRACE_H
#define MONTECARLO_COHERENTRACE_H

#include "stdinc.h"
#include "Interaction.h"
#include "MiTableProvider.h"

class CoherentRace : public Interaction
{
public:
    void Interact(photon::Photon& photon) override;
    InteractionType GetInteractionType() override;
private:
    static int getZFromMatter(MiTableProvider::MatterType matter);
    static double calculateTheta(photon::Photon& photon);
private:
    static log4cplus::Logger logger;
};


#endif //MONTECARLO_COHERENTRACE_H
