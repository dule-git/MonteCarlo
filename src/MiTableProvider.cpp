//
// Created by dusan on 09-Jan-22.
//
#include <fstream>
#include "MiTableProvider.h"

std::vector<std::vector<std::vector<double>>> MiTableProvider::miTables = std::vector<std::vector<std::vector<double>>>(MI_TABLE_COLUMN_COUNT);
log4cplus::Logger MiTableProvider::logger = log4cplus::Logger::getInstance("MiTableProvider");

void MiTableProvider::LoadMiTables(std::vector<MiTableFileName> miTableFileNames)
{
    LOG4CPLUS_INFO(logger, "Loading mi tables...");
    for (MiTableFileName miTableFileName : miTableFileNames)
    {
        readMiTableFromFile(miTableFileName);
    }
}

void MiTableProvider::readMiTableFromFile(MiTableFileName miTableFileName)
{
    std::fstream miFile;
    miFile.open(miTableFileName.miTableFileName, std::ios::in);
    LOG4CPLUS_INFO(logger, "Loading mi table from file: " << miTableFileName.miTableFileName);
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
            
            miTables[miTableFileName.matterType].push_back(miTableRow);
        }
        LOG4CPLUS_INFO(logger, "Loaded mi table from file: " << miTableFileName.miTableFileName);
    }
    else
    {
        LOG4CPLUS_ERROR(logger, "Failed to open file: " << miTableFileName.miTableFileName);
    }
}

double MiTableProvider::GetMi(double energy, MiTableProvider::MatterType matter, MiTableColumnIndex columnIndex)
{
    uint32_t rowIndexLow = 0;
    uint32_t rowIndexHigh = miTables[matter].size();
    uint32_t rowIndex = (rowIndexLow + rowIndexHigh) / 2;
    
    while (true)
    {
        if (energy >= miTables[matter][rowIndex][PHOTON_ENERGY_INDEX] && energy <= miTables[matter][rowIndex+1][PHOTON_ENERGY_INDEX])
            return miTables[matter][rowIndex][columnIndex];
        else if (energy <= miTables[matter][rowIndex][PHOTON_ENERGY_INDEX])
        {
            rowIndexHigh = rowIndex;
        }
        else
        {
            rowIndexLow = rowIndex;
        }
        rowIndex = (rowIndexLow + rowIndexHigh) / 2;
    }
}

