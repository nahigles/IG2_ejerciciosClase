#version 330 core
in vec2 vUv0;
uniform sampler2D textura1;
uniform sampler2D textura2;
uniform float BF;
uniform float intLuzAmb;
out vec4 fFragColor;

void main() 
{ 
    vec3 color1 = vec3(texture(textura1, vUv0));
    vec3 color2 = vec3(texture(textura2, vUv0));
    vec3 color = mix(color1, color1, BF) * intLuzAmb;
    fFragColor = vec4(color, 1.0);
}