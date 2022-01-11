//
// Created by dusan on 17-Dec-21.
//

#ifndef MONTECARLO_PHOTON_H
#define MONTECARLO_PHOTON_H

#include "stdinc.h"
#include "Vector3D.h"
#include "MiTableProvider.h"

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
    class Photon
    {
    public:
        static int ID;
        static constexpr double STARTING_PHOTON_ENERGY = 1.40e-1;
    public:
        Photon(geometry::Phantom& bodyPhantom, detector::Detector& detector);
        void Start();
        void Join();
        int GetId() const;
        geometry::Vector3D GetPositionVector();
        geometry::Vector3D GetDirectionVector();
        void SetCurrentMatter(MiTableProvider::MatterType currentMatter);
    private:
        void photonProcedure();
        void initDirectionVector();
        double calculateTravelDistance(bool& hasExperiencedInteraction);
    private:
        int id;
        geometry::Phantom& bodyPhantom;
        detector::Detector& detector;
        thread *photonThread;
        geometry::Vector3D positionVector;
        geometry::Vector3D directionVector;
        double energy;
        MiTableProvider::MatterType currentMatter;
    private:
        static log4cplus::Logger logger;
    };
    
}
#endif //MONTECARLO_PHOTON_H
