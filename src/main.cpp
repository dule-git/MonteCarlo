#include <iostream>
#include <csignal>
#include <log4cplus/initializer.h>
#include <ctime>
#include "main.h"
#include "PhotonGenerator.h"
#include "Detector.h"
#include "Ellipsoid.h"
#include "MiTableProvider.h"

using namespace std;
using namespace photon;
using namespace detector;
using namespace geometry;

log4cplus::Logger logger;

int main(int argc, char** argv)
{
    srand(time(NULL));
    
    ::log4cplus::initialize();
    ::log4cplus::PropertyConfigurator::doConfigure("log4cplus_configure.ini");
   
    logger = log4cplus::Logger::getInstance("Main");

//    signal(SIGINT, signalHandler);

    Arguments arguments = parseArguments(argc, argv);
    LOG4CPLUS_INFO(logger, "Arguments parsed.");
    LOG4CPLUS_INFO(logger, "Total number of photons: " << arguments.TOTAL_NUM_OF_PHOTONS);
    LOG4CPLUS_INFO(logger, "Number of photons in parallel: " << arguments.NUM_OF_PARALLEL_PHOTONS);
    
    MiTableProvider::LoadMiTables(vector<MiTableProvider::MiTableFileName>{
        MiTableProvider::MiTableFileName("mi_attenuation_coeff_H2O.txt", MiTableProvider::MatterType::H20)
    });
    Detector detector;
    Ellipsoid ellipsoid("EllipsoidBody",MiTableProvider::MatterType::H20,300,300,60);
    
    PhotonGenerator::TOTAL_NUM_OF_PHOTONS = arguments.TOTAL_NUM_OF_PHOTONS;
    PhotonGenerator::NUM_OF_PARALLEL_PHOTONS = arguments.NUM_OF_PARALLEL_PHOTONS;
    PhotonGenerator photonGenerator(detector, ellipsoid);
    
    photonGenerator.Join();
    
    return 0;
}

//void signalHandler(int signum)
//{
//    if (signum == SIGINT)
//    {
//        photonGenerator->StopGenerating();
//    }
//}

Arguments parseArguments(int argc, char** argv)
{
    Arguments arguments;
    
    if (argc < 2)
    {
        LOG4CPLUS_ERROR(logger, "Not enough arguments provided. Use case: >MonteCarlo.exe totalNumOfPhotons numOfParallelPhotons");
        exit(1);
    }
    else
    {
        string total_num_of_photons_string(argv[1]);
        string num_of_parallel_photons_string(argv[2]);
        
        arguments.TOTAL_NUM_OF_PHOTONS = stoi(total_num_of_photons_string);
        arguments.NUM_OF_PARALLEL_PHOTONS = stoi(num_of_parallel_photons_string);
    }
    
    return arguments;
}

double random()
{
    return (double)((double) rand() / ((double) RAND_MAX));
}

void Log(const std::string& message)
{
    std::cout << message << "\n";
}