#include "logic/input_manager.h"

InputManager::InputManager()
{
}

void InputManager::BindKeyCallback(KeyboardKey _key, KeyCallbackPtr _callback)
{
    m_KeyMap[_key] = _callback;
}

void InputManager::Update()
{
    for (auto& binding : m_KeyMap)
    {
        if (IsKeyPressed(binding.first))
        {
            binding.second();
        }
    }
}
