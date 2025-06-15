#pragma once

#include "raylib.h"

class Geometry
{
public:
    enum class Generated 
    {
        Cube,
        Cone,
        Sphere,
        Custom
    };

    Geometry();

    Model GetModel(Generated _selection);

    void SetShaders(Shader _shader);

    void LoadCustomModel(const char* _path);

    ~Geometry();
private:
    Model m_Cube;
    Model m_Cone;
    Model m_Sphere;
    Model m_Custom;
};