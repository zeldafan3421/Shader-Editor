#pragma once

#include "logic/shader_compiler.h"
#include "logic/window_manager.h"
#include "graphics/preview.h"
#include "graphics/geometry.h"
#include "logic/project_shaders.h"
#include "logic/input_manager.h"

class Application
{
public:
    Application();
    void Loop();
private:
    

    WindowManager m_WindowManager;      
    ProjectShaders m_UserShaders;
    Geometry m_Geometry;
    Preview m_Preview;
    InputManager m_InputManager;
};