#ifndef LINEARINDEXABLE3D_H
#define LINEARINDEXABLE3D_H


class LinearIndexable3d
{
public:
    LinearIndexable3d(int sizeI, int sizeJ, int sizeK);

    inline int linearIndex(int i, int j, int k) const
    {
        return i*m_sizeJ*m_sizeK + j*m_sizeK+k;
    }

    inline int sizeI() const
    {
        return m_sizeI;
    }

    inline int sizeJ() const
    {
        return m_sizeJ;
    }

    inline int sizeK() const
    {
        return m_sizeK;
    }

protected:
    int m_sizeI;
    int m_sizeJ;
    int m_sizeK;
};

#endif // LINEARINDEXABLE3D_H
