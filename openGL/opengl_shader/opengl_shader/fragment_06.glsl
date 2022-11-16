#version 330 core

out vec4 color;

void main ( )
{
	
	for (int i=0; i<4; i++)
	color = vec4 ( 1.0 , 0.0 , 0.0 , 1.0 );	// 빨강색으로 색상 고정
}