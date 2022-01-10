//
// Created by dusan on 07-Jan-22.
//

#include <fstream>
#include "Phantom.h"

namespace geometry
{
    Phantom::Phantom(std::string id, MiTableProvider::MatterType matterType):
        id(id),
        children(),
        logger(log4cplus::Logger::getInstance(id)),
        matterType(matterType)
    {
    }
    
    void Phantom::GetIntersectionPoints(Vector3D positionVector, Vector3D directionVector,
                                        MiTableProvider::MatterType matterFrom,
                                        std::vector<GeometryUtils::IntersectionPoint> &intersectionPoints)
    {
        std::vector<Vector3D> isPoints = IntersectsLine(positionVector, directionVector);
        
        std::vector<Vector3D> pointsInPath = GeometryUtils::GetPointsInPathOfSemiStraightLine(positionVector, directionVector, isPoints);
        
        if (pointsInPath.size() == 2)
        {
            intersectionPoints.emplace_back(pointsInPath[0], matterFrom, matterType);
            intersectionPoints.emplace_back(pointsInPath[1], matterType, matterFrom);
        }
        
        for (Phantom* child : children)
        {
            child->GetIntersectionPoints(positionVector, directionVector, matterType, intersectionPoints);
        }
    }
}