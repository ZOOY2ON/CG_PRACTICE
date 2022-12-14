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
//// ----------------------------? 이거 뭐지 ?
////#include <gl/glm/ext.hpp>
////#include <gl/glm/glm.hpp>
//
//char* filetobuf ( const char* file );
//GLvoid drawScene ( );
//GLvoid Reshape ( int w , int h );
////함수 프로토타입
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
//float vertexPosition [ ] = {
//	// 1사분면에 삼각형 만들기
//	0.5, 1.0, 0.0,			//첫번째 꼭짓점 (x, y, z)
//	0.0, 0.0, 0.0,		//두번째 꼭짓점 (원점)
//	1.0, 0.0, 0.0,			// 세번째 꼭짓점 
//
//	// 3사분면에 삼각형 만들기
//	- 0.5, 0.0, 0.0,
//	-1.0 , -1.0 , 0.0,
//	0.0 , -1.0 , 0.0
//};
//
//void main ( int argc , char** argv )														//--- 윈도우 출력하고 콜백함수 설정 
//{
//	width = 500;
//	height = 500;
//
//	//--- 윈도우 생성하기
//	glutInit ( &argc , argv );																			// glut 초기화
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// 디스플레이 모드 설정
//	glutInitWindowPosition ( 100 , 100 );													// 윈도우의 위치 지정
//	glutInitWindowSize ( width , height );												// 윈도우의 크기 지정
//	glutCreateWindow ( "main_copy" );
//
//	// --- GLEW 초기화하기
//	glewExperimental = GL_TRUE;
//	glewInit ( );
//
//	// --- 셰이더 읽어와서 셰이더 프로그램 만들기
//	make_vertexShader ( );																		// 버텍스 셰이더 만들기
//	make_fragmentShader ( );																	// 프래그먼트 셰이더 만들기
//	make_shaderProgram ( );																	// 셰이더 프로그램 만들기
//
//	InitBuffer ( );
//
//	glutDisplayFunc ( drawScene );														// 출력 콜백 함수
//	glutReshapeFunc ( Reshape );
//	//glutMouseFunc ( Mouse );
//	glutMainLoop ( );
//}
//
//// --- 콜백 함수 : 그리기 콜백
//GLvoid drawScene ( )
//{
//	GLfloat rColor , gColor , bColor;
//
//	rColor = gColor = 0.0;
//	bColor = 1.0;	// 배경색을 파랑색으로
//	glClearColor ( rColor , gColor , bColor , 1.0f );
//	glClear ( GL_COLOR_BUFFER_BIT );
//
//	//glPointSize ( 10.0 );
//	InitBuffer ( );
//	glUseProgram ( shaderProgram );													// 쉐이더 사용
//	glDrawArrays ( GL_TRIANGLES , 0 , 6 );											// (도형 / 0 부터 / n 까지) 
//
//	glutSwapBuffers ( );	// 화면에 출력하기
//}
//
//// --- 콜백 함수 : 다시 그리기 콜백
//GLvoid Reshape ( int w , int h )
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
//GLuint VAO , VBO_pos;
//
//GLvoid InitBuffer ( )
//{
//	glGenVertexArrays ( 1 , &VAO );															// (갯수, 종류) -> 1개를 VAO로 만들겠다
//	glGenBuffers ( 1 , &VBO_pos );
//
//	//데이터를 넣어주기전 알려주기 -> 바인드
//	glBindVertexArray ( VAO );
//
//	glBindBuffer ( GL_ARRAY_BUFFER , VBO_pos );
//	//VBO_pos에 데이터 넣어주기 : vertexPosition 데이터를 넣어줌
//	glBufferData ( GL_ARRAY_BUFFER , sizeof ( vertexPosition ) , vertexPosition , GL_STATIC_DRAW );
//
//	//데이터의 구성을 알려줘야함
//	//( 0번에다가 / 3개의 크기 전달:vec 3이므로 / 타입 / 노말라이즈 안함 / 크기 : 3개의 속성을 가지고 있음 * 하나당 float만큼 크기를 가져옴 / 시작번지 : 0번 )
//	glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 3 * sizeof ( float ) , 0 );
//
//	glEnableVertexAttribArray ( 0 );
//
//}
//
//// --- vertex 셰이더 불러와서 객체 만들기
//void make_vertexShader ( )
//{
//	GLchar* vertexSource;
//
//	// 임무 : 버텍스 셰이더 읽어와서 객체 만들고 컴파일 하기
//	vertexSource = filetobuf ( "vertex.glsl" );	// 읽어오기
//	vertexShader = glCreateShader ( GL_VERTEX_SHADER );	// 객체 만들기
//	glShaderSource ( vertexShader , 1 , &vertexSource , NULL );	// 객체에 코드 넣어주기 ('만들어줄 것', '만들 갯수', '넣어줄 곳', ?)
//	glCompileShader ( vertexShader );	// 컴파일
//
//	// --- 에러 체크
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( vertexShader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( vertexShader , 512 , NULL , errorLog );
//		std::cerr << "ERROR : vertex shader 컴파일 실패\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//// --- fragment 셰이더 불러와서 객체 만들기
//void make_fragmentShader ( )
//{
//	GLchar* fragmentSource;
//
//	// 임무 : 프래그먼트 셰이더 읽어와서 객체 만들고 컴파일 하기
//	fragmentSource = filetobuf ( "fragment.glsl" );	// 읽어오기
//	fragmentShader = glCreateShader ( GL_FRAGMENT_SHADER );	// 객체 만들기
//	glShaderSource ( fragmentShader , 1 , &fragmentSource , NULL );	// 객체에 코드 넣어주기 ('만들어줄 것', '만들 갯수', '넣어줄 곳', ?)
//	glCompileShader ( fragmentShader );	// 컴파일
//
//	// --- 에러 체크
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( fragmentShader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( fragmentShader , 512 , NULL , errorLog );
//		std::cerr << "ERROR : fragment shader 컴파일 실패\n" << errorLog << std::endl;
//		return;
//	}
//}
//
//// --- 셰이더 프로그램
//void make_shaderProgram ( )
//{
//	shaderProgram = glCreateProgram ( );
//
//	glAttachShader ( shaderProgram , vertexShader );	// 셰이더 프로그램에 vertex 셰이더 붙여주기
//	glAttachShader ( shaderProgram , fragmentShader );	// 셰이더 프로그램에 fragment 셰이더 붙여주기
//	glLinkProgram ( shaderProgram );	// vertex 셰이더 프로그램과 fragment 셰이더 프로그램을 하나로 만들어 주기
//
//	// 셰이더 객체는 셰이더 프로그램을 통해 사용 됨. -> 각각의 객체를 삭제 해줘도 됨
//	glDeleteShader ( vertexShader );
//	glDeleteShader ( fragmentShader );
//
//	// --- 에러 체크
//	GLint result;
//	GLchar errorLog [ 512 ];
//
//	glGetProgramiv ( shaderProgram , GL_LINK_STATUS , &result );	// 셰이더가 잘 연결되었는지 체크
//	if ( !result ) {
//		glGetProgramInfoLog ( shaderProgram , 512 , NULL , errorLog );
//		std::cerr << "ERROR : shader program 연결 실패\n" << errorLog << std::endl;
//		return;
//	}
//
//	glUseProgram ( shaderProgram );
//}
//
//
//// --- 파일 불러오기
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