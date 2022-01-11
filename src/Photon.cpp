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

namespace photon
{
    int Photon::ID = 0;
    
    log4cplus::Logger Photon::logger = log4cplus::Logger::getInstance("Photon");
    
    Photon::Photon(geometry::Phantom& bodyPhantom) :
            bodyPhantom(bodyPhantom),
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
            double s = 0;
            double tau = -log(1 - random()) * 100;
            std::vector<double> miFactors;
            std::vector<double> mis;
            std::vector<geometry::GeometryUtils::IntersectionPoint> intersectionPoints;
            
            bodyPhantom.GetIntersectionPoints(positionVector, directionVector, currentMatter, intersectionPoints);
            for (int i = 0; i < intersectionPoints.size() - 1; i++)
            {
                if (intersectionPoints[i].matterFrom == MiTableProvider::VACUM)
                {
                    s += geometry::GeometryUtils::Distance(positionVector, intersectionPoints[i].point);
                }

                double s_i = geometry::GeometryUtils::Distance(intersectionPoints[i].point, intersectionPoints[i+1].point);
                double mi = MiTableProvider::GetMi(energy, intersectionPoints[i].matterTo, MiTableProvider::MiTableColumnIndex::TOTAL_WITH_COHERENT_INDEX);

                mis.push_back(mi);
                miFactors.push_back(s_i * mi);

                if (vector_sum(miFactors) >= tau)
                {
                    std::vector<double> miFactorsPrim(miFactors.size() - 1);
                    copy(miFactors.begin(), miFactors.end() - 1, miFactorsPrim.begin());

                    double sumMiFactorsPrim = vector_sum(miFactorsPrim);
                    s += (tau - sumMiFactorsPrim) / mis[mis.size() - 1];

                    running = false;
                }
            }
        }
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
