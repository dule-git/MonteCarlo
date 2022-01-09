//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_GEOMETRYUTILS_H
#define MONTECARLO_GEOMETRYUTILS_H

namespace geometry
{

class Vector3D;

class GeometryUtils
{
public:
    static Vector3D LineThroughPlaneIntersectPoint(Vector3D& rayVector, Vector3D& rayPoint, Vector3D& planeNormal, Vector3D& planePoint);
    
};

}
#endif //MONTECARLO_GEOMETRYUTILS_H
