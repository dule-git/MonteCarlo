//
// Created by dusan on 17-Dec-21.
//

#ifndef MONTECARLO_PHOTON_H
#define MONTECARLO_PHOTON_H

#include "stdinc.h"
#include "Vector3D.h"

using namespace std;

namespace photon
{
    class Photon
    {
    public:
        static int ID;
    public:
        Photon();
        void Start();
        void Join();
        int GetId() const;
        geometry::Vector3D GetPositionVector();
        geometry::Vector3D GetDirectionVector();
    private:
        void photonProcedure();
        void initDirectionVector();
    private:
        int id;
        thread *photonThread;
        geometry::Vector3D positionVector;
        geometry::Vector3D directionVector;
    private:
        static log4cplus::Logger logger;
    };
    
}
#endif //MONTECARLO_PHOTON_H
