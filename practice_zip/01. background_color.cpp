//#include <iostream>
//#include <gl/glew.h> //--- 필요한 헤더파일 include
//#include <gl/freeglut.h>
//#include <gl/freeglut_ext.h>
//
//#include<cstdlib>
//#include<ctime>
//#include<windows.h>
//
//GLvoid drawScene ( GLvoid );
//GLvoid Reshape ( int w , int h );
//GLvoid keyboard ( unsigned char key , int x , int y );
//GLvoid My_Timer ( int value );
//
//// --- RGB
//float R = 1.0; float G = 1.0; float B = 1.0; float F = 1.0;
//bool timer_onoff;
//
//void Timer_st ( int value );
//void Timer_nd ( int value );
//
//void main ( int argc , char** argv )															//--- 윈도우 출력하고 콜백함수 설정 
//{
//
//
//	//--- 윈도우 생성하기
//	glutInit ( &argc , argv );																			// glut 초기화
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// 디스플레이 모드 설정
//	glutInitWindowPosition ( 0 , 0 );															// 윈도우의 위치 지정
//	glutInitWindowSize ( 800 , 600 );														// 윈도우의 크기 지정
//	glutCreateWindow ( "background_color" );													// 윈도우 생성( 윈도우 이름)
//
//	//--- GLEW 초기화하기
//	glewExperimental = GL_TRUE;
//	if ( glewInit ( ) != GLEW_OK )																// glew 초기화
//	{
//		std::cerr << "Unable to initialize GLEW" << std::endl;
//		exit ( EXIT_FAILURE );
//	}
//	else
//		std::cout << "GLEW Initialized\n";
//
//	glutDisplayFunc ( drawScene );															// 출력 함수의 지정
//	glutReshapeFunc ( Reshape );															// 다시 그리기 함수 지정
//	glutKeyboardFunc ( keyboard );
//	glutTimerFunc ( 100, My_Timer, 1 );
//	glutMainLoop ( );																						// 이벤트 처리 시작 
//}
//
//GLvoid My_Timer ( int value )
//{
//	if ( timer_onoff == true ) {
//		keyboard ( 'A' , 0 , 0 );
//	}
//	else if ( timer_onoff == false ) {
//		
//	}
//	glutPostRedisplay ( );
//	glutTimerFunc ( 100 , My_Timer , 1 );
//}
//
//GLvoid drawScene ( )																				//--- 콜백 함수: 그리기 콜백 함수 
//{
//	glClearColor ( R, G, B, F );																	// 바탕색을 ‘white’ 로 지정
//	glClear ( GL_COLOR_BUFFER_BIT );												// 설정된 색으로 전체를 칠하기
//	glutSwapBuffers ( );																				// 화면에 출력하기
//}
//
//GLvoid Reshape ( int w , int h )																//--- 콜백 함수: 다시 그리기 콜백 함수 
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
//GLvoid keyboard ( unsigned char key , int x , int y )
//{
//	int num = 0;
//	switch ( key ) {
//	case'R':
//		R = 1.0; G = 0.0; B = 0.0; F = 0.0;
//		break;
//	case'G':
//		R = 0.0; G = 1.0; B = 0.0; F = 0.0;
//		break;
//	case'B':
//		R = 0.0; G = 0.0; B = 1.0; F = 0.0;
//		break;
//	case'K':
//		R = 0.0; G = 0.0; B = 0.0; F = 0.0;
//		break;
//	case'W':
//		R = 1.0; G = 1.0; B = 1.0; F = 1.0;
//		break;
//	case'A':
//		srand ( ( unsigned int ) time ( NULL ) );
//		num = rand ( ) % 5 + 1;
//
//		if ( num == 1 ) {
//			R = 1.0; G = 0.0; B = 0.0; F = 0.0;
//		}
//		else if ( num == 2 ) {
//			R = 0.0; G = 1.0; B = 0.0; F = 0.0;
//		}
//		else if ( num == 3 ) {
//			R = 0.0; G = 0.0; B = 1.0; F = 0.0;
//		}
//		else if ( num == 4 ) {
//			R = 0.0; G = 0.0; B = 0.0; F = 0.0;
//		}
//		else if ( num == 5 ) {
//			R = 1.0; G = 1.0; B = 1.0; F = 1.0;
//		}
//		else
//			std::cout << "오류" << std::endl;
//		break;
//	case'T':
//		timer_onoff = true;
//		glutTimerFunc ( 100 , My_Timer , 1 );
//		break;
//	case'S':
//		timer_onoff = false;
//		break;
//	case 'Q':
//		exit(0);
//	}
//	glutPostRedisplay ( );
//}