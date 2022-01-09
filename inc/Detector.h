//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_DETECTOR_H
#define MONTECARLO_DETECTOR_H

#include "Vector3D.h"

namespace detector
{
    class Detector
    {
    public:
        Detector();
        geometry::Vector3D GetPositionVector();
        geometry::Vector3D GetPerpendicularVector();
        bool Contains(geometry::Vector3D& point) const;
    private:
        geometry::Vector3D positionVector;
        geometry::Vector3D perpendicularVector;
        geometry::Vector3D upperLeft, upperRight, lowerLeft, lowerRight;
    private:
        static constexpr double WIDTH = 380.0;
        static constexpr double HEIGHT = 380.0;
    };
}

#endif //MONTECARLO_DETECTOR_H
