#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 u_ModelMatrix;
uniform mat4 u_ViewProjection;

void main()
{
    //gl_Position = u_ViewProjection * u_ModelMatrix * vec4(aPos, 1.0);
    gl_Position = u_ModelMatrix * vec4(aPos, 1.0);
}