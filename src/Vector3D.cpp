//
// Created by dusan on 07-Jan-22.
//

#include "../inc/Vector3D.h"

namespace geometry
{
    
    Vector3D::Vector3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    double Vector3D::Dot(const Vector3D& rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    
    Vector3D Vector3D::operator-(const Vector3D& rhs) const
    {
        return Vector3D{x - rhs.x, y - rhs.y, z - rhs.z};
    }
    
    Vector3D Vector3D::operator*(double rhs) const
    {
        return Vector3D{rhs*x, rhs*y, rhs*z};
    }
    
    Vector3D Vector3D::operator+(const Vector3D &rhs) const
    {
        return Vector3D{x + rhs.x, y + rhs.y, z + rhs.z};
    }
    
    std::ostream& operator<<(std::ostream& os, const Vector3D& vector)
    {
        os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
        return os;
    }
    
}