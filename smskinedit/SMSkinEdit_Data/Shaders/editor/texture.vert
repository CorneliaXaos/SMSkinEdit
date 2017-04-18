#version 330 core

in struct VertexData {
    vec3 position;
    vec2 uvs;
} vertexData;

out struct FragmentData {
    vec2 uvs;
} fragmentData;

uniform mat4 modelTransform; // should always include camera transform

void main() {
   gl_Position = modelTransform * vec4(vertexData.position, 1); 
   fragmentData.uvs = vec2(vertexData.uvs.x, 1 - vertexData.uvs.y);
}
