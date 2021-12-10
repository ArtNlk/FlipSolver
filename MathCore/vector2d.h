#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D(double x = 0.0, double y = 0.0);

    inline double x() const;
    inline double y() const;

    inline void setX(double x);
    inline void setY(double y);

    inline void dot(const Vector2D& other);
    inline void cross(const Vector2D& other);
    static inline double dot(const Vector2D& v1, const Vector2D& v2);
    static inline Vector2D cross(const Vector2D& v1, const Vector2D& v2);

    Vector2D &operator*=(double factor);
    Vector2D &operator*=(const Vector2D &other);
    Vector2D &operator+=(const Vector2D &other);

    Vector2D &operator/=(double divisor);
    Vector2D &operator/=(const Vector2D &other);
    Vector2D &operator-=(const Vector2D &other);

    double &operator[](int i);
    double operator[](int i) const;

protected:
    double m_x;
    double m_y;
};

#endif // VECTOR2D_H
