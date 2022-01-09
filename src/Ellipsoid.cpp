//
// Created by dusan on 08-Jan-22.
//

#include "Ellipsoid.h"
namespace geometry
{
    Ellipsoid::Ellipsoid(double a, double b, double c, std::string miFileName) :
        Phantom("Ellipsoid", miFileName),
        a(a),
        b(b),
        c(c)
    {
    
    }
    
    bool Ellipsoid::Contains(geometry::Vector3D point)
    {
        return false;
    }
    
    std::vector<Vector3D> Ellipsoid::IntersectsLine(Vector3D positionVector, Vector3D directionVector)
    {
        double x0 = positionVector.x, y0 = positionVector.y, z0 = positionVector.z;
        double dx = directionVector.x, dy = directionVector.y, dz = directionVector.z;
        
        double k = pow(dx*b*c, 2) + pow(dy*a*c, 2) + pow(dz*a*b, 2);
        double l = 2*x0*dx*pow(b*c, 2) + 2*y0*dy*pow(a*c, 2) + 2*z0*dz*pow(a*b, 2);
        double m = pow(x0*b*c, 2) + pow(y0*a*c, 2) + pow(z0*a*b, 2) - pow(a*b*c, 2);
        
        double t1 = (-l + sqrt(pow(l, 2) - 4*k*m)) / (2*k);
        double t2 = (-l - sqrt(pow(l, 2) - 4*k*m)) / (2*k);
        
        std::vector<Vector3D> intersectionPoints;
        if (!isnan(t1))
            intersectionPoints.push_back(positionVector + directionVector*t1);
        if (!isnan(t2))
            intersectionPoints.push_back(positionVector + directionVector*t2);
        
        return intersectionPoints;
    }
    
    
}
