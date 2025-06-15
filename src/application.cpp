#include "application.h"

Application::Application()
    : m_WindowManager(), m_UserShaders(),  m_Geometry(), 
    m_Preview(m_Geometry.GetModel(Geometry::Generated::Cube))
{    
}

void Application::Loop()
{
    while (!WindowShouldClose())
    {
        m_Preview.Update();
        m_UserShaders.Update(m_Geometry);
        m_WindowManager.Update();
        UpdateInput();

        BeginDrawing();
            ClearBackground(BLACK);

            m_Preview.Draw(Vector2Zeros, m_WindowManager.GetSize());
            DrawFPS(10, 10);
        EndDrawing();
    }
}

void Application::UpdateInput()
{
    if (IsKeyPressed(KEY_ONE))
        m_Preview.SetModel(m_Geometry.GetModel(Geometry::Generated::Cube));
    
    if (IsKeyPressed(KEY_TWO))
        m_Preview.SetModel(m_Geometry.GetModel(Geometry::Generated::Cone));
    
    if (IsKeyPressed(KEY_THREE))
        m_Preview.SetModel(m_Geometry.GetModel(Geometry::Generated::Sphere));
    
    if (IsKeyPressed(KEY_FOUR))
        m_Preview.SetModel(m_Geometry.GetModel(Geometry::Generated::Custom));
}
