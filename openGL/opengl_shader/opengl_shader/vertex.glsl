#version 330 core

// 코드에서 읽어와서 사용
layout(location = 0) in vec3 vPos;

void main ( )
{
	gl_Position = vec4 ( vPos.x, vPos.y, vPos.z, 1.0 );
}