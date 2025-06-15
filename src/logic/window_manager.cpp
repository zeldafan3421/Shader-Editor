#include "logic/window_manager.h"

WindowManager::WindowManager()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_RESIZABLE);
    InitWindow(g_WindowWidth, g_WindowHeight, g_WindowTitle);  
    m_WindowSize = g_WindowSize; 
}

Vector2 WindowManager::GetSize() const
{
    return m_WindowSize;
}

const std::string WindowManager::GetDroppedFile() const
{
    std::string response;
    if (IsFileDropped()) 
    {

        FilePathList droppedFiles = LoadDroppedFiles();

        response = droppedFiles.paths[0];

        UnloadDroppedFiles(droppedFiles);
    }

    return response;
}

void WindowManager::Update()
{
    if (IsWindowResized())
    {
        m_WindowSize = Vector2{
            static_cast<float>(GetScreenWidth()),
            static_cast<float>(GetScreenHeight())};

        float aspect = g_WindowSize.x / g_WindowSize.y;
        if (aspect != m_WindowSize.x / m_WindowSize.y)
        {
            float res = m_WindowSize.x;
            SetWindowSize(res, res / aspect);
        }

        m_WindowSize = Vector2{
            static_cast<float>(GetScreenWidth()),
            static_cast<float>(GetScreenHeight())};
    }

    if (!IsWindowFocused() || IsWindowHidden())
    {
        return;
    }

    if (IsKeyPressed(KEY_F1))
    {
        if (IsWindowState(FLAG_WINDOW_UNDECORATED))
            ClearWindowState(FLAG_WINDOW_UNDECORATED);
        else 
            SetWindowState(FLAG_WINDOW_UNDECORATED);
    }
}

WindowManager::~WindowManager()
{
    CloseWindow();
}
