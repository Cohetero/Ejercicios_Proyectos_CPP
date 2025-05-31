#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
private:
    int x, y, z;

public:
    Vector3d(int x, int y, int z);
    bool esIgual(const Vector3d &vect) const;
    double normaMax() const;
};

#endif