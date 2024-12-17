#version 330 core
in vec2 vUv0;
uniform sampler2D textura1;
uniform sampler2D textura2;
uniform sampler2D textura3;
out vec4 fFragColor;

void main() 
{ 
    vec3 color1 = vec3(texture(textura1, vUv0));
    vec3 color2 = vec3(texture(textura2, vUv0));
    vec3 color3 = vec3(texture(textura3, vUv0));
    vec3 color;

    // Si es negro
    if(color1.r == 1){
        color = color2;
    }
    else{
        color = color3;
    }

    fFragColor = vec4(color, 1.0);
}