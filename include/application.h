#pragma once

#include "logic/shader_compiler.h"
#include "logic/window_manager.h"
#include "graphics/preview.h"
#include "graphics/geometry.h"
#include "logic/project_shaders.h"

class Application
{
public:
    Application();
    void Loop();
    void UpdateInput();
private:
    WindowManager m_WindowManager;      
    ProjectShaders m_UserShaders;
    Geometry m_Geometry;
    Preview m_Preview;
};