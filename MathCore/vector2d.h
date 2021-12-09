#ifndef VECTOR2D_H
#define VECTOR2D_H


class Vector2D
{
public:
    Vector2D(double x = 0.0, double y = 0.0);

    double x() const;
    double y() const;

    void setX(double x);
    void setY(double y);

    Vector2D &operator*=(double factor);
    Vector2D &operator*=(const Vector2D &other);
    Vector2D &operator+=(const Vector2D &other);

    Vector2D &operator/=(double divisor);
    Vector2D &operator/=(const Vector2D &other);
    Vector2D &operator-=(const Vector2D &other);

    double &operator[](int i);
    double operator[](int i) const;

private:
    double m_x;
    double m_y;
};

#endif // VECTOR2D_H
