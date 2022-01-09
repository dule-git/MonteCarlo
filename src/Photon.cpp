//
// Created by dusan on 17-Dec-21.
//
#define _USE_MATH_DEFINES
#include <cmath>

#include "Photon.h"
#include "PhotonGenerator.h"

namespace photon
{
    int Photon::ID = 0;
    
    log4cplus::Logger Photon::logger = log4cplus::Logger::getInstance("Photon");
    
    Photon::Photon() :
            photonThread(nullptr),
            directionVector(0,0,0),
            positionVector(PhotonGenerator::GENERATOR_POSITION_X, PhotonGenerator::GENERATOR_POSITION_Y, PhotonGenerator::GENERATOR_POSITION_Z)
    {
        id = ID++;
        LOG4CPLUS_INFO(logger, "Creating a new photon with id: " << id << ".");
        initDirectionVector();
    }
    
    void Photon::initDirectionVector()
    {
        LOG4CPLUS_INFO(logger, "Initializing Omega vector...");
        
        double theta = acos(1 - 2 * random());
        double phi = 2 * M_PI * random();
        LOG4CPLUS_DEBUG(logger, "Theta: " << theta << "; Phi: " << phi << ";");
        
        double omega_x = sin(theta) * cos(phi);
        double omega_y = sin(theta) * sin(phi);
        double omega_z = cos(theta);
        LOG4CPLUS_DEBUG(logger, "omega_x: " << omega_x << "; omega_y: " << omega_y << "; omega_z: " << omega_z << ";");
        
        directionVector = geometry::Vector3D(omega_x, omega_y, omega_z);
        
        LOG4CPLUS_INFO(logger, "Omega vector initialized.");
    }
    
    geometry::Vector3D Photon::GetPositionVector()
    {
        return positionVector;
    }
    
    geometry::Vector3D Photon::GetDirectionVector()
    {
        return directionVector;
    }
    
    void Photon::photonProcedure()
    {
        LOG4CPLUS_INFO(logger, "Photon with id: " << id << " procedure entered.");
//        this_thread::sleep_for(chrono::seconds(10));
    }
    
    void Photon::Start()
    {
        photonThread = new thread(&Photon::photonProcedure, this);
        LOG4CPLUS_INFO(logger, "Photon with id: " << id << " thread released.");
    }
    
    void Photon::Join()
    {
        if ((photonThread != nullptr) && (photonThread->joinable()))
        {
            LOG4CPLUS_INFO(logger, "Joining a photon with id: " << id << "...");
            photonThread->join();
            LOG4CPLUS_INFO(logger, "Joined a photon with id: " << id << ".");
        }
    }
    
    int Photon::GetId() const
    {
        return id;
    }
}
