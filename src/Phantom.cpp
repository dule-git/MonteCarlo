//
// Created by dusan on 07-Jan-22.
//

#include <fstream>
#include "Phantom.h"

namespace geometry
{
    int Phantom::ID = 0;
    
    Phantom::Phantom(std::string loggerName, std::string miFileName):
        id(++ID),
        children(),
        logger()
    {
        logger = log4cplus::Logger::getInstance(loggerName + std::to_string(id));
        
        std::fstream miFile;
        miFile.open(miFileName, std::ios::in);
        if (miFile.is_open())
        {
            while (!miFile.eof())
            {
                std::vector<double> miTableRow(MI_TABLE_COLUMN_COUNT);
                miFile >> miTableRow[PHOTON_ENERGY_INDEX];
                miFile >> miTableRow[COHERENT_SCATTER_INDEX];
                miFile >> miTableRow[INCOHERENT_SCATTER_INDEX];
                miFile >> miTableRow[PHOTO_ELECTRIC_ABS_INDEX];
                miFile >> miTableRow[TOTAL_WITH_COHERENT_INDEX];
                
                miTable.push_back(miTableRow);
            }
            LOG4CPLUS_INFO(logger, "Read Mi Table from file: " << miFileName);
        }
        else
        {
            LOG4CPLUS_ERROR(logger, "Failed to open file: " << miFileName);
        }
    }
}