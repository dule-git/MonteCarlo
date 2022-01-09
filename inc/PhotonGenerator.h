//
// Created by dusan on 17-Dec-21.
//

#ifndef MONTECARLO_PHOTONGENERATOR_H
#define MONTECARLO_PHOTONGENERATOR_H

#include "stdinc.h"

using namespace std;

namespace geometry
{
    class Phantom;
}

namespace detector
{
    class Detector;
}

namespace photon
{
    class Photon;
    
    class PhotonGenerator
    {
    public:
        static int TOTAL_NUM_OF_PHOTONS;
        static int NUM_OF_PARALLEL_PHOTONS;
        static constexpr double GENERATOR_POSITION_X = 0.0;
        static constexpr double GENERATOR_POSITION_Y = 0.0;
        static constexpr double GENERATOR_POSITION_Z = -100.0;
    public:
        PhotonGenerator(detector::Detector& detector, geometry::Phantom& phantom);
        void StopGenerating();
        void Join();
    private:
        void photonGeneratorProcedure();
        Photon* generateNewPhoton();
        void waitForAllPhotonsToFinish();
    private:
        detector::Detector& detector;
        geometry::Phantom& phantom;
        thread *photonGeneratorThread;
        queue<Photon *> photons;
        bool running;
    private:
        static log4cplus::Logger logger;
    };
}
#endif //MONTECARLO_PHOTONGENERATOR_H
