//
// Created by dusan on 19-Jan-22.
//

#ifndef MONTECARLO_DISTRIBUTIONFUNCTIONTABLEPROVIDER_H
#define MONTECARLO_DISTRIBUTIONFUNCTIONTABLEPROVIDER_H

#include "stdinc.h"

class DistributionFunctionTableProvider
{
public:
    static void InitTables();
    static double GetXSquared(int Z, double x_max, double epsilon1);
private:
    static const std::string COEFFICIENTS_FILE_NAME;
    static constexpr int P_i = 0;
    static constexpr int X_i = 0;
private:
    static void loadCoefficients();
    static void makePXTables();
    static double calculateP(int Z, double x);
    static void getIndicesOfSurroundingValues(int Z, double P,int& i,int& j);
    static double calculateX(int Z, double P, int i, int j);
private:
    static std::vector<std::vector<double>> coefficients;
    static std::map<int, std::vector<std::vector<double>>> PXTables;
private:
    static log4cplus::Logger logger;
};


#endif //MONTECARLO_DISTRIBUTIONFUNCTIONTABLEPROVIDER_H
