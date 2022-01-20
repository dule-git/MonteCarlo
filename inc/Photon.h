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
        static constexpr double STARTING_PHOTON_ENERGY = 1.40e-1; // [KeV]
        static constexpr double ELECTRON_MASS = 9.1093837015e-31;   // [kg]
        static constexpr double SPEED_OF_LIGHT = 299792458;       // [m/s]
    public:
        Photon(geometry::Phantom& bodyPhantom, detector::Detector& detector);
        void Start();
        void Join();
        int GetId() const;
        geometry::Vector3D GetPositionVector();
        geometry::Vector3D GetDirectionVector();
        double GetEnergy() const;
        void SetCurrentMatter(MiTableProvider::MatterType currentMatter);
        MiTableProvider::MatterType GetCurrentMatter() const;
    private:
        void photonProcedure();
        void initDirectionVector();
        double calculateTravelDistance(bool& hasExperiencedInteraction);
        double getTau() const;
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
