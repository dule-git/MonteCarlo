//
// Created by dusan on 08-Jan-22.
//

#ifndef MONTECARLO_ELLIPSOID_H
#define MONTECARLO_ELLIPSOID_H

#include "Phantom.h"

namespace geometry
{

class Ellipsoid : public Phantom
{
public:
    Ellipsoid(double a, double b, double c, std::string miFileName);
    bool Contains(Vector3D point) override;
    std::vector<Vector3D> IntersectsLine(Vector3D positionVector, Vector3D directionVector);
public:
    double a,b,c;
};

}

#endif //MONTECARLO_ELLIPSOID_H
