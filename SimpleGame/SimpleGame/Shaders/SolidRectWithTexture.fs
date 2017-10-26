#version 330

layout(location=0) out vec4 FragColor;

in vec2 v_TexPosition;

uniform sampler2D s_Texture;
uniform vec4 u_Color;

void main()
{
	FragColor = texture2D(s_Texture, v_TexPosition);
}
