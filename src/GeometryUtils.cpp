//
// Created by dusan on 07-Jan-22.
//

#include "../inc/GeometryUtils.h"
#include "../inc/Vector3D.h"

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

}