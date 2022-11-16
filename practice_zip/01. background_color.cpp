//#include <iostream>
//#include <gl/glew.h> //--- �ʿ��� ������� include
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
//void main ( int argc , char** argv )															//--- ������ ����ϰ� �ݹ��Լ� ���� 
//{
//
//
//	//--- ������ �����ϱ�
//	glutInit ( &argc , argv );																			// glut �ʱ�ȭ
//	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// ���÷��� ��� ����
//	glutInitWindowPosition ( 0 , 0 );															// �������� ��ġ ����
//	glutInitWindowSize ( 800 , 600 );														// �������� ũ�� ����
//	glutCreateWindow ( "background_color" );													// ������ ����( ������ �̸�)
//
//	//--- GLEW �ʱ�ȭ�ϱ�
//	glewExperimental = GL_TRUE;
//	if ( glewInit ( ) != GLEW_OK )																// glew �ʱ�ȭ
//	{
//		std::cerr << "Unable to initialize GLEW" << std::endl;
//		exit ( EXIT_FAILURE );
//	}
//	else
//		std::cout << "GLEW Initialized\n";
//
//	glutDisplayFunc ( drawScene );															// ��� �Լ��� ����
//	glutReshapeFunc ( Reshape );															// �ٽ� �׸��� �Լ� ����
//	glutKeyboardFunc ( keyboard );
//	glutTimerFunc ( 100, My_Timer, 1 );
//	glutMainLoop ( );																						// �̺�Ʈ ó�� ���� 
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
//GLvoid drawScene ( )																				//--- �ݹ� �Լ�: �׸��� �ݹ� �Լ� 
//{
//	glClearColor ( R, G, B, F );																	// �������� ��white�� �� ����
//	glClear ( GL_COLOR_BUFFER_BIT );												// ������ ������ ��ü�� ĥ�ϱ�
//	glutSwapBuffers ( );																				// ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape ( int w , int h )																//--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
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
//			std::cout << "����" << std::endl;
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