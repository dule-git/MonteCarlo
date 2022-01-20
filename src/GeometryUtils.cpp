//
// Created by dusan on 07-Jan-22.
//

#include "../inc/GeometryUtils.h"
#include "../inc/Vector3D.h"
#include <cmath>

namespace geometry
{

Vector3D GeometryUtils::LineThroughPlaneIntersectPoint(Vector3D &rayVector, Vector3D &rayPoint, Vector3D &planeNormal, Vector3D &planePoint)
{
    Vector3D diff = rayPoint - planePoint;
    double prod1 = diff.Dot(planeNormal);
    double prod2 = rayVector.Dot(planeNormal);
    double prod3 = prod1 / prod2;
    return rayPoint - rayVector * prod3;
}
    
    std::vector<Vector3D> GeometryUtils::GetPointsInPathOfSemiStraightLine(Vector3D positionVector, Vector3D directionVector, const std::vector<Vector3D>& pointsToCheck)
    {
        std::vector<Vector3D> pointsInPath;
        for (Vector3D pointToCheck : pointsToCheck)
        {
            Vector3D subVector = pointToCheck - positionVector;
            if (signbit(subVector.x) == signbit(directionVector.x)
                && signbit(subVector.y) == signbit(directionVector.y)
                && signbit(subVector.z) == signbit(directionVector.z))
            {
                pointsInPath.push_back(pointToCheck);
            }
        }
        
        return pointsInPath;
    }
    
    double GeometryUtils::Distance(Vector3D pointFrom, Vector3D pointTo)
    {
        double dx = pointFrom.x - pointTo.x;
        double dy = pointFrom.y - pointTo.y;
        double dz = pointFrom.z - pointTo.z;
        
        return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
    }
    
    std::vector<GeometryUtils::IntersectionPoint> GeometryUtils::SortIntersectionPointsByDistanceFromGenerator(Vector3D positionVector, std::vector<IntersectionPoint> intersectionPoints)
    {
        std::vector<IntersectionPoint> sortedIntersectionPoints;
        
        while (!intersectionPoints.empty())
        {
            double minDistance = ULONG_MAX;
            IntersectionPoint minIntersectionPoint;
            for (IntersectionPoint intersectionPoint: intersectionPoints)
            {
                double distance = Distance(positionVector, intersectionPoint.point);
                if (minDistance >= distance)
                {
                    minDistance = distance;
                    minIntersectionPoint = intersectionPoint;
                }
            }
            sortedIntersectionPoints.push_back(minIntersectionPoint);
            remove_if(intersectionPoints.begin(), intersectionPoints.end(), [minIntersectionPoint](IntersectionPoint ip)
            {
                return ip.point.x == minIntersectionPoint.point.x && ip.point.y == minIntersectionPoint.point.y && ip.point.z == minIntersectionPoint.point.z;
            });
            intersectionPoints.resize(intersectionPoints.size() - 1);
        }
        
        return sortedIntersectionPoints;
    }
    
}