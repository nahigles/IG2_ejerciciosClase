#version 330 core
in vec2 vUv0;
uniform sampler2D texturaL;
uniform sampler2D texturaM;
uniform float BF;
uniform float intLuzAmb;
out vec4 fFragColor;

void main() 
{ 
    //vec3 colorL = vec3(texture(texturaL, vUv0));
    //vec3 colorM = vec3(texture(texturaM, vUv0));
    //vec3 color = mix(colorL, colorM, BF) * intLuzAmb;
    fFragColor = vec4(1, 0.5, 0.2, 1.0);
}