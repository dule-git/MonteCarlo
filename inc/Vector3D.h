//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_VECTOR3D_H
#define MONTECARLO_VECTOR3D_H

#include "stdinc.h"

namespace geometry
{
    
class Vector3D {
public:
    Vector3D(double x, double y, double z);
    double Dot(const Vector3D& rhs) const;
    Vector3D operator-(const Vector3D& rhs) const;
    Vector3D operator+(const Vector3D& rhs) const;
    Vector3D operator*(double rhs) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector);
public:
    double x, y, z;
};

    
}


#endif //MONTECARLO_VECTOR3D_H
