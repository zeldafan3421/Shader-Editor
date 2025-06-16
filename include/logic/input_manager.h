#pragma once

#include "raylib.h"

#include <functional>
#include <unordered_map>

class InputManager
{
public:
    using KeyCallbackPtr = std::function<void(void)>;

    InputManager();

    void BindKeyCallback(KeyboardKey _key, KeyCallbackPtr _callback);
    void Update();
private:
    std::unordered_map<KeyboardKey, KeyCallbackPtr> m_KeyMap;
};