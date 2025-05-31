#include <cmath>
#include "Vector3d.h"

Vector3d ::Vector3d(int x, int y, int z) : x(x), y(y), z(z) {}

bool Vector3d::esIgual(const Vector3d &vect) const
{
    return (x == vect.x && y == vect.y && z == vect.z);
}

double Vector3d::normaMax() const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}