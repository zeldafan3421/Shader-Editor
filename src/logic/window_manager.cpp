#include "logic/window_manager.h"

WindowManager::WindowManager()
{
    SetConfigFlags(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_RESIZABLE);
    InitWindow(g_WindowWidth, g_WindowHeight, g_WindowTitle);  
    m_WindowSize = g_WindowSize; 
    SetTargetFPS(60);

    AddListener(std::make_unique<ResizeDefaultListener>());
}

const Vector2 WindowManager::GetSize() const
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

bool WindowManager::IsDecorated() const
{
    return !IsWindowState(FLAG_WINDOW_UNDECORATED);
}

void WindowManager::Update()
{
    if (IsWindowResized())
        SendEvent(Event::Resized);

    if (IsFileDropped())
        SendEvent(Event::FileIsDropped);
}

void WindowManager::SetTargetFPS(int _target)
{
    ::SetTargetFPS(_target);
}

void WindowManager::ToggleDecoration()
{
    if (IsDecorated())
    {
        SetWindowState(FLAG_WINDOW_UNDECORATED);
    }
    else 
    {
        ClearWindowState(FLAG_WINDOW_UNDECORATED);
    }
}

void WindowManager::AddListener(std::unique_ptr<Listener>&& _listener)
{
    m_Listeners.push_back(std::move(_listener));
}

WindowManager::~WindowManager()
{
    CloseWindow();
}

int WindowManager::GetFPS() const
{
    return ::GetFPS();
}

void WindowManager::SendEvent(Event _event)
{
    for (auto& listener : m_Listeners)
    {
        listener->OnRecieve(_event, *this);
    }
}

void WindowManager::ResizeDefaultListener::OnRecieve(Event _event, WindowManager& _instance)
{
    if (_event != Event::Resized)
        return;

    // Update the window size to the current screen size
    _instance.m_WindowSize = {
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight())
    };

    // Maintain the original aspect ratio if it has changed
    float originalAspect = g_WindowSize.x / g_WindowSize.y;
    float currentAspect = _instance.m_WindowSize.x / _instance.m_WindowSize.y;

    if (std::abs(originalAspect - currentAspect) > 0.01f) // Allow small tolerance
    {
        float newWidth = _instance.m_WindowSize.x;
        float newHeight = newWidth / originalAspect;
        SetWindowSize(static_cast<int>(newWidth), static_cast<int>(newHeight));

        // Update the window size again after resizing
        _instance.m_WindowSize = {
            static_cast<float>(GetScreenWidth()),
            static_cast<float>(GetScreenHeight())
        };
    }
}

WindowManager::FileDefaultListener::FileDefaultListener(std::function<void(void)> _callback)
    : m_Callback(_callback)
{
}

void WindowManager::FileDefaultListener::OnRecieve(Event _event, WindowManager& _instance)
{
    if (_event == Event::FileIsDropped) 
        m_Callback();
}