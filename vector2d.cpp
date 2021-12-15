#include "vector2d.h"

#include <cmath>
#include <stdexcept>

Vector2D::Vector2D(double x, double y):
    m_x(x),
    m_y(y)
{
}

double Vector2D::x() const
{
    return m_x;
}

double Vector2D::y() const
{
    return m_y;
}

void Vector2D::setX(double x)
{
    m_x = x;
}

void Vector2D::setY(double y)
{
    m_y = y;
}

double Vector2D::dot(const Vector2D &other) const
{
    return m_x*other.x() + m_y*other.y();
}

double Vector2D::cross(const Vector2D &other) const
{
    return m_x*other.y() - m_y*other.x();
}

void Vector2D::normalize()
{
    double len = std::sqrt(m_x*m_x + m_y*m_y);
    if(len == 0)
    {
        return;
    }
    m_x/=len;
    m_y/=len;
}

Vector2D Vector2D::normalized() const
{
    double len = std::sqrt(m_x*m_x + m_y*m_y);
    if(len == 0)
    {
        Vector2D(0,0);
    }
    return Vector2D(m_x/len,m_y/len);
}

double Vector2D::length() const
{
    return std::sqrt(m_x*m_x + m_y*m_y);
}

Vector2D &Vector2D::operator*=(double factor)
{
    m_x*=factor;
    m_y*=factor;

    return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &other)
{
    m_x*=other.x();
    m_y*=other.y();

    return *this;
}

Vector2D &Vector2D::operator+=(const Vector2D &other)
{
    m_x+=other.x();
    m_y+=other.y();

    return *this;
}

Vector2D &Vector2D::operator/=(double divisor)
{
    if(divisor == 0)
    {
        throw std::invalid_argument("Vector2D division by zero!");
    }
    m_x/=divisor;
    m_y/=divisor;

    return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &other)
{
    if(other.x() == 0 || other.y() == 0)
    {
        throw std::invalid_argument("Vector2D division by zero x or y vector!");
    }

    m_x/=other.x();
    m_y/=other.y();

    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other)
{
    m_x-=other.x();
    m_y-=other.y();

    return *this;
}

double &Vector2D::operator[](int i)
{
    switch (i)
    {
    case 0:
        return m_x;
        break;

    case 1:
        return m_y;
        break;

    default:
        throw std::out_of_range("Vector2D indexing out of range!");
        break;
    }
}

double Vector2D::operator[](int i) const
{
    if(i < 0 || i >= 2)
    {
        throw std::out_of_range("Vector2D const indexing out of range!");
    }

    return (&m_x)[i];
}
