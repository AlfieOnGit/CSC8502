#include "Moon.h"

Moon::Moon(float radius, Vector3 const &pos)
{
    mesh = Mesh::LoadFromMeshFile("Sphere.msh");
    SetModelScale(Vector3(radius, radius, radius));
    SetTransform(Matrix4::Translation(pos));
    SetBoundingRadius(10.0f);
}

Moon::~Moon()
{
    delete mesh;
}
