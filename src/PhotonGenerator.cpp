//
// Created by dusan on 17-Dec-21.
//

#include "PhotonGenerator.h"
#include "Photon.h"
#include "Detector.h"
#include "GeometryUtils.h"
#include "Phantom.h"

namespace photon
{
// Initialized with command line arguments in main()
    int PhotonGenerator::TOTAL_NUM_OF_PHOTONS = -1;
    int PhotonGenerator::NUM_OF_PARALLEL_PHOTONS = -1;
    
    log4cplus::Logger PhotonGenerator::logger = log4cplus::Logger::getInstance("PhotonGenerator");
    
    PhotonGenerator::PhotonGenerator(detector::Detector& detector, geometry::Phantom& phantom) :
        detector(detector),
        phantom(phantom),
        photonGeneratorThread(nullptr),
        photons(),
        running(true)
    {
        photonGeneratorThread = new thread(&PhotonGenerator::photonGeneratorProcedure, this);
        LOG4CPLUS_INFO(logger, "Thread released.");
    }
    
    void PhotonGenerator::StopGenerating()
    {
        running = false;
        LOG4CPLUS_INFO(logger, "Signaled to exit.");
    }
    
    void PhotonGenerator::photonGeneratorProcedure()
    {
        LOG4CPLUS_INFO(logger, "Procedure entered.");
        for (int i = 0; i < PhotonGenerator::NUM_OF_PARALLEL_PHOTONS; i++)
        {
            photons.push(generateNewPhoton());
        }
        
        for (uint32_t i = 0; i < PhotonGenerator::TOTAL_NUM_OF_PHOTONS && running; i++)
        {
            Photon *photon = photons.front();
            photons.pop();
            
            photon->Join();
            delete photon;
            
            photons.push(generateNewPhoton());
        }
    
        waitForAllPhotonsToFinish();
        
        LOG4CPLUS_INFO(logger, "Exited procedure.");
    }
    
    Photon *PhotonGenerator::generateNewPhoton()
    {
        Photon* photon;
        
        while (true)
        {
            photon = new Photon(phantom, detector);
            geometry::Vector3D photonPositionVector = photon->GetPositionVector();
            geometry::Vector3D photonDirectionVector = photon->GetDirectionVector();
    
            if (photonDirectionVector.z <= 0)
            {
                LOG4CPLUS_DEBUG(logger, "Photon with id: " << photon->GetId() << " is going in opposite direction. Making new photon...");
                delete photon;
                continue;
            }
            
            vector<geometry::Vector3D> intersectionPoints = phantom.IntersectsLine(photonPositionVector, photonDirectionVector);
            if (!intersectionPoints.empty())
            {
                LOG4CPLUS_DEBUG(logger, "Created photon with id: " << photon->GetId() << " will hit the phantom.");
                break;
            }
            else
            {
                LOG4CPLUS_DEBUG(logger, "Created photon with id: " << photon->GetId() << " won't hit the phantom. Making new photon...");
                delete photon;
            }
        }
        photon->Start();
        return photon;
    }
    
    void PhotonGenerator::Join()
    {
        if ((photonGeneratorThread != nullptr) && (photonGeneratorThread->joinable()))
        {
            LOG4CPLUS_INFO(logger, "Joining PhotonGenerator thread...");
            photonGeneratorThread->join();
            LOG4CPLUS_INFO(logger, "PhotonGenerator thread joined.");
        }
    }
    
    void PhotonGenerator::waitForAllPhotonsToFinish()
    {
        for (int i = 0; i < photons.size(); i++)
        {
            Photon *photon = photons.front();
            photons.pop();
            
            photon->Join();
            delete photon;
        }
    }
}

