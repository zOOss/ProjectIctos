#sginclude "://shaders/commonlight.vert.inc"

uniform float Time;

in vec2 textureCoords;
out vec2 texCoords;
out vec3 viewPosition;
out vec3 viewNormal;

void main()
{
    float angle = 200*Time;
    float angle2 = 100 * Time;
    mat4 rotationsMatrixX;
    mat4 rotationsMatrixY;
    rotationsMatrixX = mat4(1, 0, 0, 0,
                           0, cos(angle), -sin(angle), 0,
                           0, sin(angle), cos(angle), 0,
                           0, 0, 0, 1);

    rotationsMatrixY = mat4(cos(angle2), 0, sin(angle2), 0,
                        0, 1, 0, 0,
                        -sin(angle2), 0, cos(angle2), 0,
                        0, 0, 0, 1);


    vec4 rotatedPos = rotationsMatrixY * rotationsMatrixX * vertexPosition;

    vec4 newPosition = vec4(rotatedPos.xyz, 1.0);
    newPosition.z = rotatedPos.z;

    viewPosition = eyePosition().xyz;
    viewNormal = eyeNormalVec().xyz;
    texCoords = textureCoords;

    gl_Position = projectionMatrix*modelViewMatrix*newPosition;
}
