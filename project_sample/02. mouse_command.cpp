//#include <iostream>
//#include <gl/glew.h> //--- 필요한 헤더파일 include
//#include <gl/freeglut.h>
//#include <gl/freeglut_ext.h>
//
//#include<cstdlib>
//#include<ctime>
//
//GLvoid drawScene ( GLvoid );
//GLvoid Reshape( int w , int h );
//GLvoid Display ( );
//GLvoid mouseBtn ( int btn, int states, int x , int y );
//
//// --- RGB
//int R = 0; int G = 0; int B = 0; int F = 0;
//int r = 1; int g = 1; int b = 1; int f = 1;
//float size = 0;
//
//void main ( int argc , char** argv )															//--- 윈도우 출력하고 콜백함수 설정 
//{ 
//	//--- 윈도우 생성하기
//	glutInit ( &argc , argv );																			// glut 초기화
//	//glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// 디스플레이 모드 설정
//	//glutInitWindowPosition ( 100 , 100 );													// 윈도우의 위치 지정
//	//glutInitWindowSize ( 300 , 300 );														// 윈도우의 크기 지정
//	glutCreateWindow ( "mouse_command" );														// 윈도우 생성( 윈도우 이름)
//
//	//--- GLEW 초기화하기
//	glewExperimental = GL_TRUE;
//	if ( glewInit ( ) != GLEW_OK	)																// glew 초기화
//	{
//	std::cerr << "Unable to initialize GLEW" << std::endl;
//	exit ( EXIT_FAILURE );
//	}
//	else
//	std::cout << "GLEW Initialized\n";
//
//	glutDisplayFunc ( drawScene );
//	glutDisplayFunc ( Display );																// 출력 함수의 지정
//	glutReshapeFunc ( Reshape );															// 다시 그리기 함수 지정
//	glutMouseFunc ( mouseBtn );															// 마우스 입력 함수 지정
//	glutMainLoop ( );																						// 이벤트 처리 시작 
//} 
//
//GLvoid drawScene ( )																				//--- 콜백 함수: 그리기 콜백 함수 
//{ 
//	glClearColor( R, G, B, F );													
//	glClear ( GL_COLOR_BUFFER_BIT );												// 설정된 색으로 전체를 칠하기
//	// 그리기 부분 구현: 그리기 관련 부분이 여기에 포함된다.
//
//	glutSwapBuffers ( );																				// 화면에 출력하기
//}
//
//GLvoid Reshape ( int w , int h )																//--- 콜백 함수: 다시 그리기 콜백 함수 
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
//// 사각형 그리기
//GLvoid Display ( )
//{
//	glColor4f ( r , g , b , f );
//	glClear ( GL_COLOR_BUFFER_BIT );
//
//	glBegin ( GL_POLYGON );
//	glVertex3f ( -0.5-size , -0.5- size , 0.0 );
//	glVertex3f ( 0.5+size , -0.5-size , 0.0 );
//	glVertex3f ( 0.5+size , 0.5+size , 0.0 );
//	glVertex3f ( -0.5-size , 0.5+size , 0.0 );
//
//	glEnd ( );
//	glFlush ( );
//}
//
//GLvoid mouseBtn (int btn, int states, int x , int y )
//{
//	int check = 0;
//
//	if ( ( float ) x > 100-(200*size) && ( float ) x < 200+ ( 200 * size ) )
//		if ( ( float ) y > 100- ( 200 * size ) && ( float ) y < 200+ ( 200 * size ) )
//			check = 1;
//	else
//		check = 0;
//
//	if ( btn == GLUT_LEFT_BUTTON ) {
//		if ( check == 1 ) {
//			srand ( ( unsigned int ) time ( NULL ) );
//			r = rand ( ) % 2;
//			g = rand ( ) % 2;
//			b = rand ( ) % 2;
//			f = rand ( ) % 2;
//
//			Display ( );
//		}
//		else if ( check == 0 ) {
//			srand ( ( unsigned int ) time ( NULL ) );
//			R = rand ( ) % 2;
//			G = rand ( ) % 2;
//			B = rand ( ) % 2;
//			F = rand ( ) % 2;
//			
//			drawScene ( );
//			Display ( );
//		}
//	}
//	else if ( btn == GLUT_RIGHT_BUTTON ) {
//		
//		if ( check == 1 )
//			size += 0.05;
//		
//		else if ( check == 0 )
//			size += -0.05;
//			
//		Display ( );
//	}
//	else
//		std::cout << "오류" << std::endl;
//}