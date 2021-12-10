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

    inline void dot(const Vector3D& other);
    inline void cross(const Vector3D& other);
    static inline double dot(const Vector3D& v1, const Vector3D& v2);
    static inline Vector3D cross(const Vector3D& v1, const Vector3D& v2);

protected:
    double m_x;
    double m_y;
    double m_z;
};

#endif // VECTOR3D_H
