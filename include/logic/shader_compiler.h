#pragma once

#include "raylib.h"

constexpr char g_VertexShaderCode[] = R"(
    #version 330

    // Input vertex attributes
    in vec3 vertexPosition; // vertex position relative to origin
    in vec2 vertexTexCoord; // texture coord of vertex

    // Input uniform values
    uniform mat4 mvp; // model-view-projection

    // Output vertex attributes (to fragment shader)
    out vec2 fragTexCoord;

    void main()
    {
        // Pass texture coord
        fragTexCoord = vertexTexCoord;
        // Calculate final vertex position
        gl_Position = mvp*vec4(vertexPosition, 1.0);
    }
)";

constexpr char g_FragmentShaderCode[] = R"(
    #version 330

    // Input vertex attributes (from vertex shader)
    in vec3 fragPosition;
    in vec2 fragTexCoord;

    // Input uniform values
    uniform sampler2D texture0;
    uniform vec4 colDiffuse;

    // Output fragment color
    out vec4 finalColor;

    void main()
    {
        // Texel color fetching from texture sampler
        vec4 texelColor = texture(texture0, fragTexCoord);
        // colorize texture with diffuse color
        finalColor = colDiffuse*texelColor;
    }
)";

class ShaderCompiler
{
public:
    static Shader CompileShaders(const char* vsCode, const char* fsCode);
    static Shader LoadAndCompileShaders(const char* _vsPath, const char* _fsPath);
    static Shader CompileBuiltinShaders();
};