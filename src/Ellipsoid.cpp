//
// Created by dusan on 08-Jan-22.
//

#include "Ellipsoid.h"
namespace geometry
{
    Ellipsoid::Ellipsoid(std::string id, MiTableProvider::MatterType matterType, Vector3D positionVector, double a, double b, double c) :
        Phantom(id, matterType, positionVector),
        a(a),
        b(b),
        c(c)
    {
        LOG4CPLUS_INFO(logger, "Made an ellipsoid with id: " << id);
    }
    
    bool Ellipsoid::Contains(geometry::Vector3D point)
    {
        return false;
    }
    
    std::vector<Vector3D> Ellipsoid::IntersectsLine(Vector3D positionVector, Vector3D directionVector)
    {
        double xl = positionVector.x, yl = positionVector.y, zl = positionVector.z;
        double xp = this->positionVector.x, yp = this->positionVector.y, zp = this->positionVector.z;
        double dx = directionVector.x, dy = directionVector.y, dz = directionVector.z;
    
        double k = pow(dx * b * c, 2) + pow(dy * a * c, 2) + pow(dz * a * b, 2);
        double l = 2 * (xl-xp) * dx * pow(b * c, 2) + 2 * (yl-yp) * dy * pow(a * c, 2) + 2 * (zl-zp) * dz * pow(a * b, 2);
        double m = pow(b * c, 2) * (pow(xl, 2) - 2*xl*xp + pow(xp, 2)) + pow(a * c, 2) * (pow(yl, 2) - 2*yl*yp + pow(yp, 2)) + pow(a * b, 2)*(pow(zl, 2) - 2*zl*zp + pow(zp, 2)) - pow(a * b * c, 2);
    
        double t1 = (-l - sqrt(pow(l, 2) - 4 * k * m)) / (2 * k);
        double t2 = (-l + sqrt(pow(l, 2) - 4 * k * m)) / (2 * k);
    
        std::vector<Vector3D> intersectionPoints;
        if (!isnan(t1))
            intersectionPoints.push_back(positionVector + directionVector * t1);
        if (!isnan(t2))
            intersectionPoints.push_back(positionVector + directionVector * t2);
        
        return intersectionPoints;
    }
    
    
}
