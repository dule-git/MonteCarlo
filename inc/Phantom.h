//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_PHANTOM_H
#define MONTECARLO_PHANTOM_H

#include "stdinc.h"
#include "Vector3D.h"
#include "MiTableProvider.h"
#include "GeometryUtils.h"

namespace geometry
{
    class Phantom
    {
    public:
        Phantom(std::string id, MiTableProvider::MatterType matterType);
        void GetIntersectionPoints(Vector3D positionVector, Vector3D directionVector, MiTableProvider::MatterType matterFrom, std::vector<GeometryUtils::IntersectionPoint>& intersectionPoints);
        void AddChild(Phantom* child);
        virtual bool Contains(Vector3D point) = 0;
        virtual std::vector<Vector3D> IntersectsLine(Vector3D positionVector, Vector3D directionVector) = 0;
    protected:
        std::vector<Phantom*> children;
        std::vector<std::vector<double>> miTable;
        std::string id;
        MiTableProvider::MatterType matterType;
    protected:
        log4cplus::Logger logger;
    };
}

#endif //MONTECARLO_PHANTOM_H
