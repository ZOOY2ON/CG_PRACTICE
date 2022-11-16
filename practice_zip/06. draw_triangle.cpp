//#include <iostream>
//#include<fstream>
//#include<string>
//
//#include <gl/glew.h> //--- 필요한 헤더파일 include
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
////--- 세이더 프로그램 생성하기
//GLuint s_program;
//
//const GLfloat triShape [ 3 ][ 3 ] = { //--- 삼각형 위치 값
//{ -0.5, -0.5, 0.0 }, { 0.5, -0.5, 0.0 }, { 0.0, 0.5, 0.0} };
//
//const GLfloat colors [ 3 ][ 3 ] = { //--- 삼각형 꼭지점 색상
//{ 1.0, 0.0, 0.0 }, { 0.0, 1.0, 0.0 }, { 0.0, 0.0, 1.0 } };
//
////--------------------------------------------------------
//void main ( int argc , char** argv ) //--- 윈도우 출력하고 콜백함수 설정
//{
//	//--- 윈도우 생성하기
//	glutInit ( &argc , argv );
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );
//	glutInitWindowPosition ( 100 , 100 );
//	glutInitWindowSize ( 800 , 600 );
//	glutCreateWindow ( "draw_triangle" );
//	//--- GLEW 초기화하기
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
//	ifstream i_file ( file );	//파일 열기
//	if ( i_file.is_open ( ) ) {
//		while ( getline ( i_file , line ) ) {
//			int text = line.length ( );
//		}
//		i_file.close ( );		//파일 닫기
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
//	//--- 버텍스 세이더 객체 만들기
//	vertexshader = glCreateShader ( GL_VERTEX_SHADER );
//
//	//--- 세이더 코드를 세이더 객체에 넣기
//	glShaderSource ( vertexshader , 1 , ( const GLchar** ) &vertexsource , 0 );
//
//	//--- 버텍스 세이더 컴파일하기
//	glCompileShader ( vertexshader );
//
//	//--- 컴파일이 제대로 되지 않은 경우: 에러 체크
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( vertexshader, GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( vertexshader , 512 , NULL , errorLog );
//		std::cerr << "ERROR: vertex shader 컴파일 실패\n" << errorLog << std::endl;
//		return false;
//	}
//}
//
//bool make_fragmentShader ( )
//{
//	fragmentsource = FTB ( "fragment.glsl" );
//
//	//--- 프래그먼트 세이더 객체 만들기
//	fragmentshader = glCreateShader ( GL_FRAGMENT_SHADER );
//
//	//--- 세이더 코드를 세이더 객체에 넣기
//	glShaderSource ( fragmentshader , 1 , ( const GLchar** ) &fragmentsource , 0 );
//
//	//--- 프래그먼트 세이더 컴파일
//	glCompileShader ( fragmentshader );
//
//	//--- 컴파일이 제대로 되지 않은 경우: 컴파일 에러 체크
//	GLint result;
//	GLchar errorLog [ 512 ];
//	glGetShaderiv ( fragmentshader , GL_COMPILE_STATUS , &result );
//	if ( !result )
//	{
//		glGetShaderInfoLog ( fragmentshader , 512 , NULL , errorLog );
//		std::cerr << "ERROR: fragment shader 컴파일 실패\n" << errorLog << std::endl;
//		return false;
//	}
//}
//
//GLvoid drawScene ( )
//{
//	//--- 변경된 배경색 설정
//	glClearColor ( r , g , b , 1.0f );
//
//	//glClearColor(1.0, 1.0, 1.0, 1.0f);
//	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
//
//	//--- 렌더링 파이프라인에 세이더 불러오기
//	glUseProgram ( s_program );
//
//	//--- 사용할 VAO 불러오기
//	glBindVertexArray ( vao );
//
//	//--- 삼각형 그리기
//	glDrawArrays ( GL_TRIANGLES , 0 , 3 );
//	glutSwapBuffers ( ); //--- 화면에 출력하기
//}
//
//GLvoid Reshape ( int w , int h )																//--- 콜백 함수: 다시 그리기 콜백 함수 
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
////--- 버퍼 생성하고 데이터 받아오기
//void InitBuffer ( )
//{
//	glGenVertexArrays ( 1 , &vao );			//--- VAO 를 지정하고 할당하기
//	glBindVertexArray ( vao );					//--- VAO를 바인드하기
//	glGenBuffers ( 2 , vbo );						//--- 2개의 VBO를 지정하고 할당하기
//
//	//--- 1번째 VBO를 활성화하여 바인드하고, 버텍스 속성 (좌표값)을 저장
//	glBindBuffer ( GL_ARRAY_BUFFER , vbo [ 0 ] );
//
//	//--- 변수 diamond 에서 버텍스 데이터 값을 버퍼에 복사한다.
//	//--- triShape 배열의 사이즈: 9 * float
//	glBufferData ( GL_ARRAY_BUFFER , 9 * sizeof ( GLfloat ) , triShape , GL_STATIC_DRAW );
//
//	//--- 좌표값을 attribute 인덱스 0번에 명시한다: 버텍스 당 3* float
//	glVertexAttribPointer ( 0 , 3 , GL_FLOAT , GL_FALSE , 0 , 0 );
//
//	//--- attribute 인덱스 0번을 사용가능하게 함
//	glEnableVertexAttribArray ( 0 );
//
//	//--- 2번째 VBO를 활성화 하여 바인드 하고, 버텍스 속성 (색상)을 저장
//	glBindBuffer ( GL_ARRAY_BUFFER , vbo [ 1 ] );
//
//	//--- 변수 colors에서 버텍스 색상을 복사한다.
//	//--- colors 배열의 사이즈: 9 *float 
//	glBufferData ( GL_ARRAY_BUFFER , 9 * sizeof ( GLfloat ) , colors , GL_STATIC_DRAW );
//
//	//--- 색상값을 attribute 인덱스 1번에 명시한다: 버텍스 당 3*float
//	glVertexAttribPointer ( 1 , 3 , GL_FLOAT , GL_FALSE , 0 , 0 );
//
//	//--- attribute 인덱스 1번을 사용 가능하게 함.
//	glEnableVertexAttribArray ( 1 );
//}
//
//void InitShader ( )
//{
//	make_vertexShader ( ); //--- 버텍스 세이더 만들기
//	make_fragmentShader ( ); //--- 프래그먼트 세이더 만들기
//
//	//-- shader Program
//	s_program = glCreateProgram ( );
//	glAttachShader ( s_program , vertexshader );
//	glAttachShader ( s_program , fragmentshader );
//	glLinkProgram ( s_program );
//	//checkCompileErrors ( s_program , "PROGRAM" );
//	
//	//--- 세이더 삭제하기
//	glDeleteShader ( vertexshader );
//	glDeleteShader ( fragmentshader );
//
//	//링크실패시 프로그램 삭제
//	GLint link_checker;
//	glGetProgramiv ( s_program , GL_LINK_STATUS , &link_checker );
//	if ( link_checker == GL_FALSE || vertexshader == 0 || fragmentshader == 0 ) {
//		glDeleteProgram ( s_program );
//		return ;
//	}
//
//	//--- Shader Program 사용하기
//	glUseProgram ( s_program );
//}