#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

    inline double x() const;
    inline double y() const;
    inline double z() const;

    inline void setX(double x);
    inline void setY(double y);
    inline void setZ(double z);

    inline double dot(const Vector3D &other) const;
    inline Vector3D cross(const Vector3D &other) const;
    inline void normalize();
    inline Vector3D normalized() const;
    inline double length() const;

    Vector3D &operator*=(double factor);
    Vector3D &operator*=(const Vector3D &other);
    Vector3D &operator+=(const Vector3D &other);

    Vector3D &operator/=(double divisor);
    Vector3D &operator/=(const Vector3D &other);
    Vector3D &operator-=(const Vector3D &other);

    double &operator[](const int i);
    double operator[](const int i) const;

protected:
    double m_x;
    double m_y;
    double m_z;
};

#endif // VECTOR3D_H
