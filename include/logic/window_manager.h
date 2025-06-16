#pragma once

#include "raylib.h"
#include <deque>
#include <string>
#include <memory>
#include <functional>

constexpr int g_WindowWidth = 1280;
constexpr int g_WindowHeight = 720;
constexpr char g_WindowTitle[] = "Shader Viewer";
constexpr Vector2 g_WindowSize{static_cast<float>(g_WindowWidth), static_cast<float>(g_WindowHeight)};

class WindowManager
{
public:
    enum class Event;

    class Listener;
    
    class ResizeDefaultListener;

    class FileDefaultListener;

    friend Listener;

public: 
    WindowManager();

    void Update();

    void SetTargetFPS(int _target);
    void ToggleDecoration();

    const Vector2 GetSize() const;
    const std::string GetDroppedFile() const;

    bool IsDecorated() const;
    int GetFPS() const;

    ~WindowManager();

    void AddListener(std::unique_ptr<Listener>&& _listener);

private:
    void SendEvent(Event _event);

    Vector2 m_WindowSize;

    std::deque<std::unique_ptr<Listener>> m_Listeners;
};

class WindowManager::Listener
{
public:
    virtual void OnRecieve(Event _event, WindowManager& _instance) = 0;
};

class WindowManager::ResizeDefaultListener : public Listener
{
public:
    virtual void OnRecieve(Event _event, WindowManager& _instance);
};

enum class WindowManager::Event
{
    FileIsDropped,
    Resized,
};

class WindowManager::FileDefaultListener : public Listener
{
public:
    FileDefaultListener(std::function<void(void)> _callback);

    virtual void OnRecieve(Event _event, WindowManager& _instance);
private:
    std::function<void(void)> m_Callback;
};