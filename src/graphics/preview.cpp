#include "graphics/preview.h"

Preview::Preview(Model _base, int _width, int _height)
    : m_ShaderAppliedModel(_base), m_RenderedImage(LoadRenderTexture(_width, _height)),
    m_Camera{Vector3Ones * 4.0f, Vector3Zeros, Vector3{0.0f, 1.0f, 0.0f}, 45.0f, CAMERA_PERSPECTIVE}
{
    SetTextureFilter(m_RenderedImage.texture, TEXTURE_FILTER_BILINEAR);
}

void Preview::SetModel(Model _model)
{
    m_ShaderAppliedModel = _model;
}

void Preview::Update()
{
    UpdateCamera(&m_Camera, CAMERA_ORBITAL);

    BeginTextureMode(m_RenderedImage);
        ClearBackground(RAYWHITE);
        BeginMode3D(m_Camera);
            DrawGrid(10, 1.0f);
            DrawModel(m_ShaderAppliedModel, Vector3Zeros, 1.0f, WHITE);
        EndMode3D();
    EndTextureMode();
}

void Preview::Draw(Vector2 _position, Vector2 _size) const
{
    Rectangle src{0.0f, 0.0f, m_RenderedImage.texture.width, -m_RenderedImage.texture.height};
    Rectangle dest{_position.x, _position.y, _size.x, _size.y};

    DrawTexturePro(m_RenderedImage.texture, src, dest, Vector2Zeros, 0.0f, WHITE);
}

Preview::~Preview()
{
    UnloadRenderTexture(m_RenderedImage);
}
