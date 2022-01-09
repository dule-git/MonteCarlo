//
// Created by dusan on 07-Jan-22.
//

#include "Detector.h"

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
    
}
