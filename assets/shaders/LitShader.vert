/* ********************************************************************************************* */
/* The mandatory part of the file begins here. */

#version 330 core
layout (location = 0) in vec3 iPos;
layout (location = 1) in vec3 iNormal;
layout (location = 2) in vec2 iTexCoord;

struct Matrix {
    mat4 transform;
    mat4 world;
    mat4 inversedWorld;
};

out Data {
    vec3 fragPos;
    vec3 normal;
    vec2 texCoord;
} data;

// out vec3 vFragPos;
// out vec3 vNormal;
// out vec2 vTexCoord;

uniform Matrix matrix;



// uniform mat4 uTransformMatrix;
// uniform mat4 uWorldMatrix;
// uniform mat4 uInversedWorldMatrix;

/* The mandatory part of the file ends here. */
/* ********************************************************************************************* */


void main() {
    // vFragPos = vec3(uWorldMatrix * vec4(iPos, 1.0));
    // vNormal = mat3(transpose(uInversedWorldMatrix)) * iNormal;
    // vTexCoord = iTexCoord;

    vFragPos

    gl_Position = uTransformMatrix * vec4(iPos, 1.0);
}