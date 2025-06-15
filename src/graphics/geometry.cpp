#include "graphics/geometry.h"

Geometry::Geometry()
{
    m_Cube = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    m_Cone = LoadModelFromMesh(GenMeshCone(0.5f, 1.0f, 10));
    m_Sphere = LoadModelFromMesh(GenMeshSphere(0.5f, 10, 10));
    m_Custom = LoadModelFromMesh(GenMeshPlane(1.0f, 1.0f, 4, 4));
}

Model Geometry::GetModel(Generated _selection)
{
    switch (_selection)
    {
    default:
        if (IsModelValid(m_Custom)) return m_Custom;
    case Generated::Cube:
        return m_Cube;
    case Generated::Sphere:
        return m_Sphere;
    case Generated::Cone:
        return m_Cone;
    }
}

void Geometry::SetShaders(Shader _shader)
{
    if (IsShaderValid(_shader))
    {
        m_Cone.materials[0].shader = _shader;
        m_Cube.materials[0].shader = _shader;
        m_Sphere.materials[0].shader = _shader;

        if (IsModelValid(m_Custom))
        {
            m_Custom.materials[0].shader = _shader;
        }
    }
}

void Geometry::LoadCustomModel(const char *_path)
{
    if (IsModelValid(m_Custom))
    {
        UnloadModel(m_Custom);
    }

    m_Custom = LoadModel(_path);
}

Geometry::~Geometry()
{
    UnloadModel(m_Cube);
    UnloadModel(m_Cone);
    UnloadModel(m_Sphere);

    if (IsModelValid(m_Custom))
    {
        UnloadModel(m_Custom);
    }
}
