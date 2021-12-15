#include "vector3d.h"

#include <cmath>
#include <stdexcept>

Vector3D::Vector3D(double x, double y, double z) :
    m_x(x),
    m_y(y),
    m_z(z)
{
}

double Vector3D::x() const
{
    return m_x;
}

double Vector3D::y() const
{
    return m_y;
}

double Vector3D::z() const
{
    return m_z;
}

void Vector3D::setX(double x)
{
    m_x = x;
}

void Vector3D::setY(double y)
{
    m_y = y;
}

void Vector3D::setZ(double z)
{
    m_z = z;
}

double Vector3D::dot(const Vector3D &other) const
{
    return m_x*other.x() + m_y*other.y() + m_z*other.z();
}

Vector3D Vector3D::cross(const Vector3D &other) const
{
    return Vector3D(m_y*other.z() - m_z*other.y(),
                    m_z*other.x() - m_x*other.z(),
                    m_x*other.y() - m_y*other.x());
}

void Vector3D::normalize()
{
    double length = std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
    if(length == 0)
    {
        return;
    }
    m_x/=length;
    m_y/=length;
    m_z/=length;
}

Vector3D Vector3D::normalized() const
{
    double length = std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
    if(length == 0)
    {
        return Vector3D(0,0,0);
    }
    return Vector3D(m_x/length,
                    m_y/length,
                    m_z/length);
}

double Vector3D::length() const
{
    return std::sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

Vector3D &Vector3D::operator*=(double factor)
{
    m_x*=factor;
    m_y*=factor;
    m_z*=factor;

    return *this;
}

Vector3D &Vector3D::operator*=(const Vector3D &other)
{
    m_x*=other.x();
    m_y*=other.y();
    m_z*=other.z();

    return *this;
}

Vector3D &Vector3D::operator+=(const Vector3D &other)
{
    m_x+=other.x();
    m_y+=other.y();
    m_z+=other.z();

    return *this;
}

Vector3D &Vector3D::operator/=(double divisor)
{
    if(divisor == 0)
    {
        throw std::invalid_argument("Vector3D division by zero!");
    }
    m_x/=divisor;
    m_y/=divisor;
    m_z/=divisor;

    return *this;
}

Vector3D &Vector3D::operator/=(const Vector3D &other)
{
    if(other.x() == 0 || other.y() == 0 || other.z() == 0)
    {
        throw std::invalid_argument("Vector3D division by zero x or y or z vector!");
    }

    m_x/=other.x();
    m_y/=other.y();
    m_z/=other.z();

    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &other)
{
    m_x-=other.x();
    m_y-=other.y();
    m_z-=other.z();

    return *this;
}

double &Vector3D::operator[](const int i)
{
    if(i < 0 || i >= 3)
    {
        throw std::out_of_range("Vector3D indexing out of range!");
    }

    return (&m_x)[i];
}
