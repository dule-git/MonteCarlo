//
// Created by dusan on 09-Jan-22.
//

#ifndef MONTECARLO_MITABLEPROVIDER_H
#define MONTECARLO_MITABLEPROVIDER_H

#include "stdinc.h"

class MiTableProvider
{
public:
    typedef enum
    {
        GENERATOR=0, VACUM=1, H20
    } MatterType;
    
    typedef struct MiTableFileName
    {
        std::string miTableFileName;
        MatterType matterType;
        MiTableFileName(std::string miTableFileName, MatterType matterType) : miTableFileName(miTableFileName), matterType(matterType) {}
    } MiTableFileName;
    
    typedef enum
    {
        PHOTON_ENERGY_INDEX = 0, COHERENT_SCATTER_INDEX, INCOHERENT_SCATTER_INDEX, PHOTO_ELECTRIC_ABS_INDEX, TOTAL_WITH_COHERENT_INDEX
    } MiTableColumnIndex;
public:
    static void LoadMiTables(std::vector<MiTableFileName> miTableFileNames);
    static double GetMi(double energy, MatterType matter, MiTableColumnIndex columnIndex);
private:
    static constexpr int MATTER_TYPE_COUNT=2;
    static constexpr int MI_TABLE_COLUMN_COUNT = 5;
private:
    static void readMiTableFromFile(MiTableFileName miTableFileName);
private:
    static std::vector<std::vector<std::vector<double>>> miTables; // vector of matrices
private:
    static log4cplus::Logger logger;
};


#endif //MONTECARLO_MITABLEPROVIDER_H
