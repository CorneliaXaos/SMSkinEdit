#version 330 core

layout (location = 0) out vec4 color;

in struct FragmentData {
    vec2 uvs;
} fragmentData;

uniform sampler2D templateTex;
uniform sampler2D actualTex;
uniform float alpha;

void main() {

    // Set our color based on the blend between the actual and template
    vec4 actualComponent = texture(actualTex, fragmentData.uvs) * alpha;
    vec4 templateComponent = texture(templateTex, fragmentData.uvs) * (1 - alpha);
    color = actualComponent + templateComponent;

}
