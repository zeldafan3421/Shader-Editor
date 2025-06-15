#pragma once

#include "raylib.h"
#include "logic/shader_compiler.h"
#include "graphics/geometry.h"

class ProjectShaders
{
public:
    ProjectShaders();

    void Update(Geometry& _geometry);

    ~ProjectShaders();
private:
    Shader m_UserShaders;
    long m_VertexTime;
    long m_FragmentTime;
};