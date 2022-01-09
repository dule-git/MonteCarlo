//
// Created by dusan on 07-Jan-22.
//

#ifndef MONTECARLO_PHANTOM_H
#define MONTECARLO_PHANTOM_H
#include "stdinc.h"
#include "Vector3D.h"

namespace geometry
{
    class Phantom
    {
    public:
        Phantom(std::string loggerName, std::string miFileName);
        virtual bool Contains(Vector3D point) = 0;
        virtual std::vector<Vector3D> IntersectsLine(Vector3D positionVector, Vector3D directionVector) = 0;
    protected:
        static constexpr int MI_TABLE_COLUMN_COUNT = 5;
        static constexpr int PHOTON_ENERGY_INDEX = 0;
        static constexpr int COHERENT_SCATTER_INDEX = 1;
        static constexpr int INCOHERENT_SCATTER_INDEX = 2;
        static constexpr int PHOTO_ELECTRIC_ABS_INDEX = 3;
        static constexpr int TOTAL_WITH_COHERENT_INDEX = 4;
    protected:
        std::vector<Phantom*> children;
        std::vector<std::vector<double>> miTable;
    protected:
        int id;
        static int ID;
    protected:
        log4cplus::Logger logger;
    };
}

#endif //MONTECARLO_PHANTOM_H
