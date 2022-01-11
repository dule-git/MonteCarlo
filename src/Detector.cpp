//
// Created by dusan on 07-Jan-22.
//

#include "Detector.h"
#include "GeometryUtils.h"

namespace detector
{
    Detector::Detector():
        positionVector(0.0, 0.0, 70.0),
        perpendicularVector(0.0, 0.0, 1.0),
        upperLeft(positionVector.x + WIDTH/2.0, positionVector.y + HEIGHT/2, positionVector.z),
        upperRight(positionVector.x - WIDTH/2.0, positionVector.y + HEIGHT/2, positionVector.z),
        lowerLeft(positionVector.x + WIDTH/2.0, positionVector.y - HEIGHT/2, positionVector.z),
        lowerRight(positionVector.x - WIDTH/2.0, positionVector.y - HEIGHT/2, positionVector.z)
    { }
    
    geometry::Vector3D Detector::GetPerpendicularVector()
    {
        return perpendicularVector;
    }
    
    geometry::Vector3D Detector::GetPositionVector()
    {
        return positionVector;
    }
    
    bool Detector::Contains(geometry::Vector3D& point) const
    {
        if (point.x < upperRight.x || point.x > upperLeft.x)
            return false;
        if (point.y < lowerLeft.y || point.y > upperLeft.y)
            return false;
        
        return true;
    }
    
    void Detector::IncrementDexelIfShot(geometry::Vector3D photonPositionVector, geometry::Vector3D photonDirectionVector)
    {
        geometry::Vector3D intersectionPoint = geometry::GeometryUtils::LineThroughPlaneIntersectPoint(photonDirectionVector, photonPositionVector, perpendicularVector, positionVector);
        if (Contains(intersectionPoint))
        {
            incrementDexel(intersectionPoint);
        }
    }
    
    void Detector::incrementDexel(geometry::Vector3D intersectionPoint)
    {
        // TODO Implement incrementation of a dexel based on the line-detector intersection point
    }
    
}
