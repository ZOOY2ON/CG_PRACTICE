/*
�ǽ� 06 
1. ȭ���� ��и鿡 �ﰢ�� 1���� �׸��� ( �̵ �ﰢ�� / ���� �ٸ� �� )
2. ���콺 Ŭ�� ��ġ�� ���ο� �ﰢ�� �׸��� ( �ﰢ�� �� ������ 4�� -> ������� ���� �� ���� ���� / ���ο� �ﰢ���� ũ�Ⱑ ���� Ŀ���ų� �۾����� )
3. Ű���� ��� - a : ������ ������ �׸���, b : ������ ������ �׸���
*/

//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <random>
//#include <stdlib.h>
//#include <stdio.h>
//
//#include <gl/glew.h>
//#include <gl/freeglut.h>
//#include <gl/freeglut_ext.h>
//// ----------------------------? �̰� ���� ?
////#include <gl/glm/ext.hpp>
////#include <gl/glm/glm.hpp>
//
//char* filetobuf ( const char* file );
//GLvoid drawScene ( );
//GLvoid Reshape ( int w , int h );
////�Լ� ������Ÿ��
//void make_vertexShader ( );
//void make_fragmentShader ( );
//void make_shaderProgram ( );
//void InitBuffer ( );
//
//GLint width , height;
//GLuint vertexShader;
//GLuint fragmentShader;
//GLuint shaderProgram;
//
//
//// VBO
//float vertexPosition [ ] = {
//	// 1��и鿡 �ﰢ�� �����
//	0.5, 0.75, 0.0,
//	0.25, 0.25, 0.0,
//	0.75, 0.25, 0.0, 
//
//	// 2��и鿡 �ﰢ�� �����
//	-0.5, 0.75, 0.0,
//	-0.75, 0.25, 0.0,	
//	-0.25, 0.25, 0.0,	
//
//	// 3��и鿡 �ﰢ�� �����
//	-0.5, -0.25, 0.0,
//	-0.75, -0.75, 0.0,
//	-0.25, -0.75, 0.0,
//
//	// 4��и鿡 �ﰢ�� �����
//	0.5, -0.25, 0.0,
//	0.25, -0.75, 0.0,
//	0.75, -0.75, 0.0
//};
//
//void main ( int argc , char** argv )														//--- ������ ����ϰ� �ݹ��Լ� ���� 
//{
//	width = 500;
//	height = 500;
//
//	//--- ������ �����ϱ�
//	glutInit ( &argc , argv );																			// glut �ʱ�ȭ
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// ���÷��� ��� ����
//	glutInitWindowPosition ( 100 , 100 );													// �������� ��ġ ����
//	glutInitWindowSize ( width , height );												// �������� ũ�� ����
//	glutCreateWindow ( "main" );
//
//	// --- GLEW �ʱ�ȭ�ϱ�
//	glewExperimental = GL_TRUE;
//	glewInit ( );
//
//	// --- ���̴� �о�ͼ� ���̴� ���α׷� �����
//	make_vertexShader ( );																		// ���ؽ� ���̴� �����
//	make_fragmentShader ( );																	// �����׸�Ʈ ���̴� �����
//	make_shaderProgram ( );																	// ���̴� ���α׷� �����
//
//	//InitBuffer ( );																							// InitBuffer�� main���� �����ϰ� �Ǹ� �� ���� �۵���
//
//	glutDisplayFunc ( drawScene );														// ��� �ݹ� �Լ�
//	glutReshapeFunc ( Reshape );
//	//glutMouseFunc ( Mouse );
//	glutMainLoop ( );
//}
//
//// --- �ݹ� �Լ� : �׸��� �ݹ�
//GLvoid drawScene ( )
//{
//	GLfloat rColor , gColor , bColor;
//
//	rColor = gColor = bColor = 1.0;
//	glClearColor ( rColor , gColor , bColor , 1.0f );
//	glClear ( GL_COLOR_BUFFER_BIT );
//	InitBuffer ( );
//	//glPointSize ( 10.0 );																				// �� ũ�� �ø���
//	glUseProgram ( shaderProgram );													// ���̴� ���
//	//glDrawArrays ( GL_TRIANGLES , 0 , 12 );										// (���� / ù ��� ���� / ����)
//	for ( int i = 0; i < 3; i++ ) {
//		glDrawArrays ( GL_LINES , i , 2 );
//	}
//
//	// GL_POINTS : �� / GL_TRIANGLES : �ﰢ�� / GL_LINE : ����
//
//	glutSwapBuffers ( );	// ȭ�鿡 ����ϱ�
//}
//
//
//// --- �ݹ� �Լ� : �ٽ� �׸��� �ݹ�
//GLvoid Reshape ( int w , int h )
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
//GLuint VAO , VBO_pos ;
////GLuint VBO_att [ 2 ];																				// ��� 2 : �� �迭(vertexPosition'N')�� �� �� �̻� �϶�
//
//GLvoid InitBuffer ( )
//{
//	// InitBuffer�� ��� ��� �� �� �ʿ����� ���� Gen~�� ���� ���ֱ� : glDeleteBuffer
//
//	glGenVertexArrays ( 1 , &VAO );															// (����, ����) -> 1���� VAO�� ����ڴ�
//	glGenBuffers ( 1 , &VBO_pos );															// ��� 1 : (����, ����) -> 1���� VBO�� ����ڴ�
//	//glGenBuffers ( 2 , VBO_att );															// ��� 2 : (����, ����) -> 2���� VBO�� ����ڴ�
//
//	//�����͸� �־��ֱ��� �˷��ֱ� -> ���ε�
//	glBindVertexArray ( VAO );
//
//	//VBO ===
//	glBindBuffer ( GL_ARRAY_BUFFER , VBO_pos );							// ��� 1
//	//glBindBuffer ( GL_ARRAY_BUFFER , VBO_att[0] );					// ��� 2
//
//	//VBO_pos�� ������ �־��ֱ� : vertexPosition �����͸� �־���
//	glBufferData ( GL_ARRAY_BUFFER , sizeof ( vertexPosition ) , vertexPosition , GL_STATIC_DRAW );
//	//=== VBO
//
//	//�������� ������ �˷������
//	//( 0�����ٰ� / 3���� ũ�� ����:vec 3�̹Ƿ� / Ÿ�� / �븻������ ���� / ũ�� : 3���� �Ӽ��� ������ ���� * �ϳ��� float��ŭ ũ�⸦ ������ / ���۹��� : 0�� )
//	glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof ( float ) , 0 );
//
//	glEnableVertexAttribArray ( 0 );
//
//}
//
//// --- vertex ���̴� �ҷ��ͼ� ��ü �����
//void make_vertexShader ( )
//{
//	GLchar* vertexSource;
//
//	// �ӹ� : ���ؽ� ���̴� �о�ͼ� ��ü ����� ������ �ϱ�
//	vertexSource = filetobuf ( "vertex.glsl" );	// �о����
//	vertexShader = glCreateShader ( GL_VERTEX_SHADER );	// ��ü �����
//	glShaderSource ( vertexShader , 1 , &vertexSource , NULL );	// ��ü�� �ڵ� �־��ֱ� ('������� ��', '���� ����', '�־��� ��', ?)
//	glCompileShader ( vertexShader );	// ������
//
//	// --- ���� üũ
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( vertexShader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( vertexShader , 512 , NULL , errorLog );
//		std::cerr << "ERROR : vertex shader ������ ����\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//// --- fragment ���̴� �ҷ��ͼ� ��ü �����
//void make_fragmentShader ( )
//{
//	GLchar* fragmentSource;
//
//	// �ӹ� : �����׸�Ʈ ���̴� �о�ͼ� ��ü ����� ������ �ϱ�
//	fragmentSource = filetobuf ( "fragment.glsl" );	// �о����
//	fragmentShader = glCreateShader ( GL_FRAGMENT_SHADER );	// ��ü �����
//	glShaderSource ( fragmentShader , 1 , &fragmentSource , NULL );	// ��ü�� �ڵ� �־��ֱ� ('������� ��', '���� ����', '�־��� ��', ?)
//	glCompileShader ( fragmentShader );	// ������
//
//	// --- ���� üũ
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( fragmentShader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( fragmentShader , 512 , NULL , errorLog );
//		std::cerr << "ERROR : fragment shader ������ ����\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//// --- ���̴� ���α׷�
//void make_shaderProgram ( )
//{
//	shaderProgram = glCreateProgram ( );
//
//	glAttachShader ( shaderProgram , vertexShader );	// ���̴� ���α׷��� vertex ���̴� �ٿ��ֱ�
//	glAttachShader ( shaderProgram , fragmentShader );	// ���̴� ���α׷��� fragment ���̴� �ٿ��ֱ�
//	glLinkProgram ( shaderProgram );	// vertex ���̴� ���α׷��� fragment ���̴� ���α׷��� �ϳ��� ����� �ֱ�
//
//	// ���̴� ��ü�� ���̴� ���α׷��� ���� ��� ��. -> ������ ��ü�� ���� ���൵ ��
//	glDeleteShader ( vertexShader );
//	glDeleteShader ( fragmentShader );
//
//	// --- ���� üũ
//	GLint result;
//	GLchar errorLog [ 512 ];
//
//	glGetProgramiv ( shaderProgram , GL_LINK_STATUS , &result );	// ���̴��� �� ����Ǿ����� üũ
//	if ( !result ) {
//		glGetProgramInfoLog ( shaderProgram , 512 , NULL , errorLog );
//		std::cerr << "ERROR : shader program ���� ����\n" << errorLog << std::endl;
//		return;
//	}
//
//	glUseProgram ( shaderProgram );
//}
///*
//1. ���� ���̴� ���α׷� ���̵� ������ �ؼ� �ٸ� �Լ����� ��밡�� �ϰ� �ϴ� ���
//2. ������ ���� ������ �־��ִ� ���
//*/
//
//
//// --- ���� �ҷ�����
//char* filetobuf ( const char* file )
//{
//	FILE* fptr;
//	long length;
//	char* buf;
//
//	fptr = fopen ( file , "rb" );
//	if ( !fptr )
//		return NULL;
//	fseek ( fptr , 0 , SEEK_END );
//	length = ftell ( fptr );
//	buf = ( char* ) malloc ( length + 1 );
//	fseek ( fptr , 0 , SEEK_SET );
//	fread ( buf , length , 1 , fptr );
//	fclose ( fptr );
//	buf [ length ] = 0;
//
//	return buf;
//}