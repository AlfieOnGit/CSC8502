#include "Orb.h"

Orb::Orb(float radius, Vector3 const pos) : SceneNode(Mesh::LoadFromMeshFile("Sphere.msh"))
{
    SetModelScale(Vector3(radius, radius, radius));
    SetTransform(Matrix4::Translation(pos));
    SetBoundingRadius(radius);
}

Orb::~Orb()
{
    delete mesh;
}

