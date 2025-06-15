#include "logic/shader_compiler.h"

Shader ShaderCompiler::CompileShaders(const char* _vsCode, const char* _fsCode)
{
    return LoadShaderFromMemory(_vsCode, _fsCode);
}

Shader ShaderCompiler::LoadAndCompileShaders(const char *_vsPath, const char *_fsPath)
{
    return LoadShader(_vsPath, _fsPath);
}

Shader ShaderCompiler::CompileBuiltinShaders()
{
    return CompileShaders(g_VertexShaderCode, g_FragmentShaderCode);
}
