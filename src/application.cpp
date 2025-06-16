#include "application.h"

Application::Application()
    : m_WindowManager(), m_UserShaders(),  m_Geometry(), 
    m_Preview(m_Geometry.GetModel(Geometry::Generated::Cube))
{    
    using GeometrySetter = std::function<void(Geometry::Generated)>;

    GeometrySetter SetModelActive = [this](Geometry::Generated _gen){
        this->m_Preview.SetModel(this->m_Geometry.GetModel(_gen));
    };

    m_InputManager.BindKeyCallback( KEY_ONE, [&SetModelActive](){
        SetModelActive(Geometry::Generated::Cube);
    } );

    m_InputManager.BindKeyCallback( KEY_TWO, [&SetModelActive](){
        SetModelActive(Geometry::Generated::Cone);
    } );

    m_InputManager.BindKeyCallback( KEY_THREE, [&SetModelActive](){
        SetModelActive(Geometry::Generated::Sphere);
    } );

    m_InputManager.BindKeyCallback( KEY_FOUR, [&SetModelActive](){
        SetModelActive(Geometry::Generated::Custom);
    } );
}

void Application::Loop()
{
    while (!WindowShouldClose())
    {
        m_Preview.Update();
        m_UserShaders.Update(m_Geometry);
        m_WindowManager.Update();
        m_InputManager.Update();

        const std::string droppedFile = m_WindowManager.GetDroppedFile();
        if (droppedFile != "")
        {
            m_Geometry.LoadCustomModel(droppedFile.c_str());
        }

        BeginDrawing();
            ClearBackground(BLACK);

            m_Preview.Draw(Vector2Zeros, m_WindowManager.GetSize());
            DrawFPS(10, 10);
        EndDrawing();
    }
}
