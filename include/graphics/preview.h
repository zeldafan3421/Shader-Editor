#pragma once 

#include "raylib.h"
#include "raymath.h"

class Preview
{
public:
    Preview(Model _base, int _width=1280, int _height=720);

    void SetModel(Model _model);
    void Update();
    void Draw(Vector2 _position, Vector2 _size) const;

    ~Preview();
private:
    Model m_ShaderAppliedModel;
    RenderTexture m_RenderedImage;
    Camera m_Camera;
};