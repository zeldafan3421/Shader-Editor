#pragma once

#include "raylib.h"
#include <string>

constexpr int g_WindowWidth = 1280;
constexpr int g_WindowHeight = 720;
constexpr char g_WindowTitle[] = "Shader Viewer";
constexpr Vector2 g_WindowSize{static_cast<float>(g_WindowWidth), static_cast<float>(g_WindowHeight)};
constexpr float g_PreviewSize = 0.5f;

class WindowManager
{
public: 
    WindowManager();

    void Update();

    Vector2 GetSize() const;

    const std::string GetDroppedFile() const;

    ~WindowManager();

private:
    Vector2 m_WindowSize;
};