//
// Created by dusan on 19-Jan-22.
//

#include <fstream>
#include "DistributionFunctionTableProvider.h"

const std::string DistributionFunctionTableProvider::COEFFICIENTS_FILE_NAME  = "distribution_function_coefficients.txt";
log4cplus::Logger DistributionFunctionTableProvider::logger  = log4cplus::Logger::getInstance("DistributionFunctionTableProvider");
std::vector<std::vector<double>> DistributionFunctionTableProvider::coefficients;
std::map<int, std::vector<std::vector<double>>> DistributionFunctionTableProvider::PXTables;

void DistributionFunctionTableProvider::InitTables()
{
    loadCoefficients();
    makePXTables();
}

void DistributionFunctionTableProvider::loadCoefficients()
{
    std::ifstream coefficientsFile;
    coefficientsFile.open(COEFFICIENTS_FILE_NAME, std::ios::in);
    if (coefficientsFile.is_open())
    {
        LOG4CPLUS_INFO(logger, "Loading coefficients from file: " << COEFFICIENTS_FILE_NAME);
        coefficients.push_back(std::vector<double>({-1,-1,-1,-1,-1,-1})); // dummy vector, so Z can start from 1
        while(!coefficientsFile.eof())
        {
            std::vector<double> coefficientsRow(6);
            coefficientsFile >> coefficientsRow[0];
            coefficientsFile >> coefficientsRow[1];
            coefficientsFile >> coefficientsRow[2];
            coefficientsFile >> coefficientsRow[3];
            coefficientsFile >> coefficientsRow[4];
            coefficientsFile >> coefficientsRow[5];
            
            coefficients.push_back(coefficientsRow);
        }
        LOG4CPLUS_INFO(logger, "Loaded coefficients from file: " << COEFFICIENTS_FILE_NAME);
    }
    else
    {
        LOG4CPLUS_ERROR(logger, "Unable to open file: " << COEFFICIENTS_FILE_NAME);
    }
    coefficientsFile.close();
}

void DistributionFunctionTableProvider::makePXTables()
{
    LOG4CPLUS_INFO(logger, "Making log-log scale P-x table...");
    for (int Z = 1; Z < 99; Z += 1)
    {
        PXTables[Z] = std::vector<std::vector<double>>();
        for (double x = 0.001; x < 10; x += 0.001)
        {
            PXTables[Z].push_back(std::vector<double>({log10(calculateP(Z, x)), log10(pow(x, 2))}));
        }
    }
    LOG4CPLUS_INFO(logger, "Finished making log-log scale P-x table.");
}

double DistributionFunctionTableProvider::calculateP(int Z, double x)
{
    double a1 = coefficients[Z][1];
    double a2 = coefficients[Z][2];
    double a3 = coefficients[Z][3];
    double a4 = coefficients[Z][4];
    double a5 = coefficients[Z][5];
    
    return Z * ((1 + a1*pow(x, 2) + a2*pow(x, 3) + a3*pow(x, 4)) / (1 + a4*pow(x, 2) + a5*pow(x, 4)));
}

double DistributionFunctionTableProvider::GetXSquared(int Z, double x_max, double epsilon1)
{
   double P = calculateP(Z, pow(x_max, 2)) * epsilon1;
   
   int i, j;
   getIndicesOfSurroundingValues(Z, P, i, j);
   
   return calculateX(Z, P, i, j);
}

void DistributionFunctionTableProvider::getIndicesOfSurroundingValues(int Z, double P, int &i, int &j)
{
    std::vector<std::vector<double>>& PXTable = PXTables[Z];
    
    uint32_t rowIndexLow = 0;
    uint32_t rowIndexHigh = PXTable.size();
    uint32_t rowIndex = (rowIndexLow + rowIndexHigh) / 2;

    double logP = log10(P);
    while (true)
    {
        if (logP >= PXTable[rowIndex][P_i] && logP <= PXTable[rowIndex+1][P_i])
        {
            i = (int)rowIndex;
            j = (int)rowIndex + 1;
            return;
        }
        else if (logP <=  PXTable[rowIndex][P_i])
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

double DistributionFunctionTableProvider::calculateX(int Z, double P, int i, int j)
{
    std::vector<std::vector<double>>& PXTable = PXTables[Z];
    double logP = log10(P);
    double w = PXTable[i][X_i] + (logP - PXTable[i][P_i]) * ((PXTable[j][X_i] - PXTable[i][X_i]) / (PXTable[j][P_i] - PXTable[i][P_i]));
    return pow(10, w);
}

