//
// Created by dusan on 17-Dec-21.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>

#include "Photon.h"
#include "PhotonGenerator.h"
#include "GeometryUtils.h"
#include "Phantom.h"
#include "Detector.h"

namespace photon
{
    int Photon::ID = 0;
    
    log4cplus::Logger Photon::logger = log4cplus::Logger::getInstance("Photon");
    
    Photon::Photon(geometry::Phantom& bodyPhantom, detector::Detector& detector) :
            bodyPhantom(bodyPhantom),
            detector(detector),
            photonThread(nullptr),
            directionVector(0,0,0),
            energy(STARTING_PHOTON_ENERGY),
            positionVector(PhotonGenerator::GENERATOR_POSITION_X, PhotonGenerator::GENERATOR_POSITION_Y, PhotonGenerator::GENERATOR_POSITION_Z),
            currentMatter(MiTableProvider::MatterType::VACUM)
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
    
    double vector_sum(std::vector<double> v)
    {
        double sum = 0;
        for (double num : v)
            sum += num;
        return sum;
    }
    
    void Photon::photonProcedure()
    {
        LOG4CPLUS_INFO(logger, "Photon with id: " << id << " procedure entered.");

        bool running = true;
        while (running)
        {
            bool hasExperiencedInteraction = false;
            double travelDistance = calculateTravelDistance(hasExperiencedInteraction);
            
            if (hasExperiencedInteraction)
            {
                // TODO Implement which type of interaction has happend and logic behind every interaction
            }
            else
            {
                detector.IncrementDexelIfShot(positionVector, directionVector);
                running = false;
            }
        }
    }
    
    double Photon::calculateTravelDistance(bool& hasExperiencedInteraction)
    {
        hasExperiencedInteraction = false;
        double travelDistance = 0;
        double tau = -log(1 - random()) * 100;
        std::vector<double> td_mi_Factors;
        std::vector<double> mis;
        std::vector<geometry::GeometryUtils::IntersectionPoint> intersectionPoints;
    
        bodyPhantom.GetIntersectionPoints(positionVector, directionVector, currentMatter, intersectionPoints);
        for (int i = 0; i < intersectionPoints.size() - 1; i++)
        {
            if (intersectionPoints[i].matterFrom == MiTableProvider::VACUM)
            {
                travelDistance += geometry::GeometryUtils::Distance(positionVector, intersectionPoints[i].point);
            }
        
            double travelDistance_i = geometry::GeometryUtils::Distance(intersectionPoints[i].point, intersectionPoints[i+1].point);
            double mi_i = MiTableProvider::GetMi(energy, intersectionPoints[i].matterTo, MiTableProvider::MiTableColumnIndex::TOTAL_WITH_COHERENT_INDEX);
        
            mis.push_back(mi_i);
            td_mi_Factors.push_back(travelDistance_i * mi_i);
        
            if (vector_sum(td_mi_Factors) >= tau)
            {
                std::vector<double> td_mi_FactorsPrim(td_mi_Factors.size() - 1);
                copy(td_mi_Factors.begin(), td_mi_Factors.end() - 1, td_mi_FactorsPrim.begin());
            
                double sum_td_mi_FactorsPrim = vector_sum(td_mi_FactorsPrim);
                travelDistance += (tau - sum_td_mi_FactorsPrim) / mis[mis.size() - 1];
            
                hasExperiencedInteraction = true;
                break;
            }
        }
        return travelDistance;
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
    
    void Photon::SetCurrentMatter(MiTableProvider::MatterType currentMatter)
    {
        this->currentMatter = currentMatter;
    }
    
}
