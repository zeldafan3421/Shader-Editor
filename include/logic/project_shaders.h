#pragma once

#include "raylib.h"
#include "shader_compiler.h"
#include "geometry.h"

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