//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_GEOMETRYUTILS_H
#define MONTECARLO_GEOMETRYUTILS_H

#include "MiTableProvider.h"
#include "Vector3D.h"

namespace geometry
{

class GeometryUtils
{
public:
    typedef struct IntersectionPoint
    {
        Vector3D point;
        MiTableProvider::MatterType matterFrom;
        MiTableProvider::MatterType matterTo;
        IntersectionPoint(Vector3D point, MiTableProvider::MatterType matterFrom, MiTableProvider::MatterType matterTo): point(point), matterFrom(matterFrom), matterTo(matterTo){}
    } IntersectionPoint;
public:
    static Vector3D LineThroughPlaneIntersectPoint(Vector3D& rayVector, Vector3D& rayPoint, Vector3D& planeNormal, Vector3D& planePoint);
    static std::vector<Vector3D> GetPointsInPathOfSemiStraightLine(Vector3D positionVector, Vector3D directionVector, const std::vector<Vector3D>& intersectionPoints);
    static double Distance(Vector3D pointFrom, Vector3D pointTo);
};

}
#endif //MONTECARLO_GEOMETRYUTILS_H
