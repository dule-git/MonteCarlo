//
// Created by dusan on 07-Jan-22.
//

#include "Detector.h"
#include "GeometryUtils.h"

namespace detector
{
    
    log4cplus::Logger Detector::logger = log4cplus::Logger::getInstance("Detector");
    
    Detector::Detector():
        positionVector(0.0, 0.0, 70.0),
        perpendicularVector(0.0, 0.0, 1.0),
        upperLeft(positionVector.x + DETECTOR_WIDTH/2.0, positionVector.y + DETECTOR_HEIGHT/2, positionVector.z),
        upperRight(positionVector.x - DETECTOR_WIDTH/2.0, positionVector.y + DETECTOR_HEIGHT/2, positionVector.z),
        lowerLeft(positionVector.x + DETECTOR_WIDTH/2.0, positionVector.y - DETECTOR_HEIGHT/2, positionVector.z),
        lowerRight(positionVector.x - DETECTOR_WIDTH/2.0, positionVector.y - DETECTOR_HEIGHT/2, positionVector.z)
    {
        for (int i = 0; i < DETECTOR_HEIGHT; i++)
            for (int j = 0; j < DETECTOR_WIDTH; j++)
                dexels[i][j] = 0;
    
        LOG4CPLUS_INFO(logger, "Made a detector with width: " << DETECTOR_WIDTH << " and height: " << DETECTOR_HEIGHT);
    }
    
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
        
        std::stringstream message;
        message << "Point of intersection between photon path and detector plane is: ip" << intersectionPoint << ". ";
        if (Contains(intersectionPoint))
        {
            incrementDexel(intersectionPoint);
            message << "ip belongs to the detector, dexel incremented.";
        }
        else
        {
            message << "ip doesn't belong to the detector, photon missed.";
        }
        LOG4CPLUS_DEBUG(logger, message.str());
    }
    
    void Detector::incrementDexel(geometry::Vector3D intersectionPoint)
    {
        // TODO Implement incrementation of a dexel based on the line-detector intersection point
        double x = intersectionPoint.x + DETECTOR_WIDTH / 2;
        double y = intersectionPoint.y + DETECTOR_HEIGHT / 2;
        
        dexels[(int)y][(int)x] += 1;
    }
    
}
