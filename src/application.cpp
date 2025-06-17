#include "application.h"

Application::Application()
    : m_WindowManager(), m_UserShaders(),  m_Geometry(), 
    m_Preview(m_Geometry.GetModel(Geometry::Generated::Cube))
{    
    using GeometrySetter = std::function<void(Geometry::Generated)>;

    GeometrySetter SetModelActive = [this](Geometry::Generated _gen){
        this->m_Preview.SetModel(this->m_Geometry.GetModel(_gen));
    };

    m_InputManager.BindKeyCallback( KEY_ONE, [SetModelActive](){
        SetModelActive(Geometry::Generated::Cube);
    } );

    m_InputManager.BindKeyCallback( KEY_TWO, [SetModelActive](){
        SetModelActive(Geometry::Generated::Cone);
    } );

    m_InputManager.BindKeyCallback( KEY_THREE, [SetModelActive](){
        SetModelActive(Geometry::Generated::Sphere);
    } );

    m_InputManager.BindKeyCallback( KEY_FOUR, [SetModelActive](){
        SetModelActive(Geometry::Generated::Custom);
    } );

    m_InputManager.BindKeyCallback( KEY_F1, [this](){
        this->m_WindowManager.ToggleDecoration();
    });

    using FileListener = WindowManager::FileDefaultListener;

    auto FileIsAny = [](const std::string& _fileName,std::initializer_list<std::string> _args){
        for (auto& arg : _args)
        {
            if (IsFileExtension(_fileName.c_str(), arg.c_str()))
            {
                return true;
            }
        }

        return false;
    };

    auto IsImageFile = [FileIsAny](const std::string& _fileName){
        return FileIsAny(_fileName, {".png", ".bmp", ".jpg"});
    };

    auto FileDropCallback = [this, IsImageFile](){
        const std::string droppedFile = this->m_WindowManager.GetDroppedFile();
        if (droppedFile == "") 
            return;

        if (IsImageFile(droppedFile))
        {
            m_Geometry.SetTexture(LoadTexture(droppedFile.c_str()));
            return;
        }
        
        this->m_Geometry.LoadCustomModel(droppedFile.c_str());
    };

    m_WindowManager.AddListener(std::make_unique<FileListener>(FileDropCallback));
}

void Application::Loop()
{
    while (!WindowShouldClose())
    {
        m_Preview.Update();
        m_UserShaders.Update(m_Geometry);
        m_WindowManager.Update();
        m_InputManager.Update();

        BeginDrawing();
            ClearBackground(BLACK);

            m_Preview.Draw(Vector2Zeros, m_WindowManager.GetSize());
            DrawFPS(10, 10);
        EndDrawing();
    }
}
