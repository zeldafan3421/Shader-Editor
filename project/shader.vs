
    #version 330

    // Input vertex attributes
    in vec3 vertexPosition; // vertex position relative to origin
    in vec2 vertexTexCoord; // texture coord of vertex

    // Input uniform values
    uniform mat4 mvp; // model-view-projection

    // Output vertex attributes (to fragment shader)
    out vec2 fragTexCoord;

    void main()
    {
        // Pass texture coord
        fragTexCoord = vertexTexCoord;
        // Calculate final vertex position
        gl_Position = mvp*vec4(vertexPosition, 1.0);
    }
