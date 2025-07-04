
    #version 330

    // Input vertex attributes (from vertex shader)
    in vec3 fragPosition;
    in vec2 fragTexCoord;

    // Input uniform values
    uniform sampler2D texture0;
    uniform vec4 colDiffuse;

    // Output fragment color
    out vec4 finalColor;

    void main()
    {
        // Texel color fetching from texture sampler
        vec4 texelColor = texture(texture0, fragTexCoord);
        // colorize texture with diffuse color
        finalColor = vec4(1.0, 0.0, 0.0, 1.0);
    }
