//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_DETECTOR_H
#define MONTECARLO_DETECTOR_H

#include "Vector3D.h"
#include <cstdint>

namespace detector
{
    class Detector
    {
    public:
        Detector();
        geometry::Vector3D GetPositionVector();
        geometry::Vector3D GetPerpendicularVector();
        bool Contains(geometry::Vector3D& point) const;
        void IncrementDexelIfShot(geometry::Vector3D photonPositionVector, geometry::Vector3D photonDirectionVector);
    private:
        void incrementDexel(geometry::Vector3D intersectionPoint);
    private:
        static constexpr double DETECTOR_WIDTH = 380.0;
        static constexpr double DETECTOR_HEIGHT = 380.0;
    private:
        geometry::Vector3D positionVector;
        geometry::Vector3D perpendicularVector;
        geometry::Vector3D upperLeft, upperRight, lowerLeft, lowerRight;
        uint16_t dexels[(int)DETECTOR_HEIGHT][(int)DETECTOR_WIDTH];
    private:
        static log4cplus::Logger logger;
    };
}

#endif //MONTECARLO_DETECTOR_H
