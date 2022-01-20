//
// Created by dusan on 19-Jan-22.
//

#include "CoherentRace.h"
#include "Photon.h"
#include "DistributionFunctionTableProvider.h"

using namespace photon;

log4cplus::Logger CoherentRace::logger = log4cplus::Logger::getInstance("CoherentRace");

void CoherentRace::Interact(photon::Photon& photon)
{
    LOG4CPLUS_DEBUG(logger, "Photon [" << photon.GetId() << " is experiencing a coherent race...");
    double theta = calculateTheta(photon);
}

double CoherentRace::calculateTheta(photon::Photon& photon)
{
    LOG4CPLUS_DEBUG(logger, "Calculating theta...");
    double kapa = (1000 * photon.GetEnergy()) / (Photon::ELECTRON_MASS * pow(Photon::SPEED_OF_LIGHT, 2));
    double x_max = 41.21484487 * kapa;
    
    double x_squared = 0;
    double cosTheta = 0;
    double epsilon1 = 0;
    double epsilon2 = 0;
    double g_cosTheta = 0;
    int Z = getZFromMatter(photon.GetCurrentMatter());
    while (true)
    {
        epsilon1 = random();
        if (x_max < 1e-4)
        {
            x_squared = epsilon1 * pow(x_max, 2);
        } else
        {
            x_squared = DistributionFunctionTableProvider::GetXSquared(Z, x_max, epsilon1);
        }
        
        cosTheta = 1 - 0.5 * (x_squared / pow(20.6074 * kapa, 2));
        epsilon2 = random();
        g_cosTheta = 0.5 * (1 + pow(cosTheta, 2));
        if (epsilon2 <= g_cosTheta)
            break;
    }
    return acos(cosTheta);
}

Interaction::InteractionType CoherentRace::GetInteractionType()
{
    return Interaction::COHERENT_RACE;
}

int CoherentRace::getZFromMatter(MiTableProvider::MatterType matter)
{
    switch (matter)
    {
        case MiTableProvider::H20:
            return 10;
        case MiTableProvider::GENERATOR:
        case MiTableProvider::VACUM:
            return 0;
        default:
            return -1;
    }
}
