//#include <iostream>
//#include<fstream>
//#include<string>
//
//#include <gl/glew.h> //--- �ʿ��� ������� include
//#include <gl/freeglut.h>
//#include <gl/freeglut_ext.h>
//
//using namespace std;
//
//GLchar *vertexsource , * fragmentsource;
//GLuint vertexshader , fragmentshader;
//
//bool make_vertexShader ( );
//bool make_fragmentShader ( );
//void InitBuffer ( );
//void InitShader ( );
//GLvoid drawScene ( );
//GLvoid Reshape ( int w , int h );
//char filetobuf ( );
//
//
//int r , g , b;
//GLuint vao , vbo [ 2 ];
////--- ���̴� ���α׷� �����ϱ�
//GLuint s_program;
//
//const GLfloat triShape [ 3 ][ 3 ] = { //--- �ﰢ�� ��ġ ��
//{ -0.5, -0.5, 0.0 }, { 0.5, -0.5, 0.0 }, { 0.0, 0.5, 0.0} };
//
//const GLfloat colors [ 3 ][ 3 ] = { //--- �ﰢ�� ������ ����
//{ 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } };
//
////--------------------------------------------------------
//void main ( int argc , char** argv ) //--- ������ ����ϰ� �ݹ��Լ� ����
//{
//	//--- ������ �����ϱ�
//	glutInit ( &argc , argv );
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );
//	glutInitWindowPosition ( 100 , 100 );
//	glutInitWindowSize ( 800 , 600 );
//	glutCreateWindow ( "draw_triangle" );
//	//--- GLEW �ʱ�ȭ�ϱ�
//	glewExperimental = GL_TRUE;
//	glewInit ( );
//	InitShader ( );
//	InitBuffer ( );
//	glutDisplayFunc ( drawScene );
//	glutReshapeFunc ( Reshape );
//	glutMainLoop ( );
//}
////--------------------------------------------------------
//
//char* FTB ( string file )
//{
//	string line;
//
//	ifstream i_file ( file );	//���� ����
//	if ( i_file.is_open ( ) ) {
//		while ( getline ( i_file , line ) ) {
//			int text = line.length ( );
//		}
//		i_file.close ( );		//���� �ݱ�
//	}
//	else {
//		cout << "Unable to open file";
//	}
//	return 0;
//}
//
//bool make_vertexShader ( )
//{
//	vertexsource = FTB ( "vertex.glsl" );
//
//	//--- ���ؽ� ���̴� ��ü �����
//	vertexshader = glCreateShader ( GL_VERTEX_SHADER );
//
//	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
//	glShaderSource ( vertexshader , 1 , ( const GLchar** ) &vertexsource , 0 );
//
//	//--- ���ؽ� ���̴� �������ϱ�
//	glCompileShader ( vertexshader );
//
//	//--- �������� ����� ���� ���� ���: ���� üũ
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( vertexshader, GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( vertexshader , 512 , NULL , errorLog );
//		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
//		return false;
//	}
//}
//
//bool make_fragmentShader ( )
//{
//	fragmentsource = FTB ( "fragment.glsl" );
//
//	//--- �����׸�Ʈ ���̴� ��ü �����
//	fragmentshader = glCreateShader ( GL_FRAGMENT_SHADER );
//
//	//--- ���̴� �ڵ带 ���̴� ��ü�� �ֱ�
//	glShaderSource ( fragmentshader , 1 , ( const GLchar** ) &fragmentsource , 0 );
//
//	//--- �����׸�Ʈ ���̴� ������
//	glCompileShader ( fragmentshader );
//
//	//--- �������� ����� ���� ���� ���: ������ ���� üũ
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( fragmentshader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( fragmentshader , 512 , NULL , errorLog );
//		std::cerr << "ERROR: fragment shader ������ ����\n" << errorLog << std::endl;
//		return false;
//	}
//}
//
//GLvoid drawScene ( )
//{
//	//--- ����� ���� ����
//	glClearColor ( r , g , b , 1.0f );
//
//	//glClearColor(1.0, 1.0, 1.0, 1.0f);
//	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//
//	//--- ������ ���������ο� ���̴� �ҷ�����
//	glUseProgram ( s_program );
//
//	//--- ����� VAO �ҷ�����
//	glBindVertexArray ( vao );
//
//	//--- �ﰢ�� �׸���
//	glDrawArrays ( GL_TRIANGLES , 0 , 3 );
//	glutSwapBuffers ( ); //--- ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape ( int w , int h )																//--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
////--- ���� �����ϰ� ������ �޾ƿ���
//void InitBuffer ( )
//{
//	glGenVertexArrays ( 1 , &vao );			//--- VAO �� �����ϰ� �Ҵ��ϱ�
//	glBindVertexArray ( vao );					//--- VAO�� ���ε��ϱ�
//	glGenBuffers ( 2 , vbo );						//--- 2���� VBO�� �����ϰ� �Ҵ��ϱ�
//
//	//--- 1��° VBO�� Ȱ��ȭ�Ͽ� ���ε��ϰ�, ���ؽ� �Ӽ� (��ǥ��)�� ����
//	glBindBuffer ( GL_ARRAY_BUFFER , vbo [ 0 ] );
//
//	//--- ���� diamond ���� ���ؽ� ������ ���� ���ۿ� �����Ѵ�.
//	//--- triShape �迭�� ������: 9 * float
//	glBufferData ( GL_ARRAY_BUFFER , 9 * sizeof ( GLfloat ) , triShape , GL_STATIC_DRAW );
//
//	//--- ��ǥ���� attribute �ε��� 0���� ����Ѵ�: ���ؽ� �� 3* float
//	glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 0 , 0 );
//
//	//--- attribute �ε��� 0���� ��밡���ϰ� ��
//	glEnableVertexAttribArray ( 0 );
//
//	//--- 2��° VBO�� Ȱ��ȭ �Ͽ� ���ε� �ϰ�, ���ؽ� �Ӽ� (����)�� ����
//	glBindBuffer ( GL_ARRAY_BUFFER , vbo [ 1 ] );
//
//	//--- ���� colors���� ���ؽ� ������ �����Ѵ�.
//	//--- colors �迭�� ������: 9 *float 
//	glBufferData ( GL_ARRAY_BUFFER , 9 * sizeof ( GLfloat ) , colors , GL_STATIC_DRAW );
//
//	//--- ������ attribute �ε��� 1���� ����Ѵ�: ���ؽ� �� 3*float
//	glVertexAttribPointer ( 1 , 3 , GL_FLOAT , GL_FALSE , 0 , 0 );
//
//	//--- attribute �ε��� 1���� ��� �����ϰ� ��.
//	glEnableVertexAttribArray ( 1 );
//}
//
//void InitShader ( )
//{
//	make_vertexShader ( ); //--- ���ؽ� ���̴� �����
//	make_fragmentShader ( ); //--- �����׸�Ʈ ���̴� �����
//
//	//-- shader Program
//	s_program = glCreateProgram ( );
//	glAttachShader ( s_program , vertexshader );
//	glAttachShader ( s_program , fragmentshader );
//	glLinkProgram ( s_program );
//	//checkCompileErrors ( s_program , "PROGRAM" );
//	
//	//--- ���̴� �����ϱ�
//	glDeleteShader ( vertexshader );
//	glDeleteShader ( fragmentshader );
//
//	//��ũ���н� ���α׷� ����
//	GLint link_checker;
//	glGetProgramiv ( s_program , GL_LINK_STATUS , &link_checker );
//	if ( link_checker == GL_FALSE || vertexshader == 0 || fragmentshader == 0 ) {
//		glDeleteProgram ( s_program );
//		return ;
//	}
//
//	//--- Shader Program ����ϱ�
//	glUseProgram ( s_program );
//}