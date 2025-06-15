#include "logic/project_shaders.h"

ProjectShaders::ProjectShaders()
{
    m_UserShaders = ShaderCompiler::CompileBuiltinShaders();

    if (!DirectoryExists("project"))
    {
        MakeDirectory("project");
    }

    ChangeDirectory("project");

    if (!FileExists("shader.vs"))
    {
        SaveFileText("shader.vs", g_VertexShaderCode);
    }

    if (!FileExists("shader.fs"))
    {
        SaveFileText("shader.fs", g_FragmentShaderCode);
    }

    m_VertexTime = 0;
    m_FragmentTime = 0;
}

void ProjectShaders::Update(Geometry& _geometry)
{
    if (m_VertexTime != GetFileModTime("shader.vs") || m_FragmentTime != GetFileModTime("shader.fs"))
    {
        Shader temp = ShaderCompiler::LoadAndCompileShaders("shader.vs", "shader.fs");

        if (IsShaderValid(temp))
        {
            UnloadShader(m_UserShaders);
            m_UserShaders = temp;

            _geometry.SetShaders(m_UserShaders);
        }
        
        m_VertexTime = GetFileModTime("shader.vs");
        m_FragmentTime = GetFileModTime("shader.fs");
    }
}

ProjectShaders::~ProjectShaders()
{
    UnloadShader(m_UserShaders);
}
