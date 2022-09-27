//#include <iostream>
//#include <gl/glew.h> //--- �ʿ��� ������� include
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
//void main ( int argc , char** argv )															//--- ������ ����ϰ� �ݹ��Լ� ���� 
//{ 
//	//--- ������ �����ϱ�
//	glutInit ( &argc , argv );																			// glut �ʱ�ȭ
//	//glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// ���÷��� ��� ����
//	//glutInitWindowPosition ( 100 , 100 );													// �������� ��ġ ����
//	//glutInitWindowSize ( 300 , 300 );														// �������� ũ�� ����
//	glutCreateWindow ( "mouse_command" );														// ������ ����( ������ �̸�)
//
//	//--- GLEW �ʱ�ȭ�ϱ�
//	glewExperimental = GL_TRUE;
//	if ( glewInit ( ) != GLEW_OK	)																// glew �ʱ�ȭ
//	{
//	std::cerr << "Unable to initialize GLEW" << std::endl;
//	exit ( EXIT_FAILURE );
//	}
//	else
//	std::cout << "GLEW Initialized\n";
//
//	glutDisplayFunc ( drawScene );
//	glutDisplayFunc ( Display );																// ��� �Լ��� ����
//	glutReshapeFunc ( Reshape );															// �ٽ� �׸��� �Լ� ����
//	glutMouseFunc ( mouseBtn );															// ���콺 �Է� �Լ� ����
//	glutMainLoop ( );																						// �̺�Ʈ ó�� ���� 
//} 
//
//GLvoid drawScene ( )																				//--- �ݹ� �Լ�: �׸��� �ݹ� �Լ� 
//{ 
//	glClearColor( R, G, B, F );													
//	glClear ( GL_COLOR_BUFFER_BIT );												// ������ ������ ��ü�� ĥ�ϱ�
//	// �׸��� �κ� ����: �׸��� ���� �κ��� ���⿡ ���Եȴ�.
//
//	glutSwapBuffers ( );																				// ȭ�鿡 ����ϱ�
//}
//
//GLvoid Reshape ( int w , int h )																//--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
//{
//	glViewport ( 0 , 0 , w , h );
//}
//
//// �簢�� �׸���
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
//		std::cout << "����" << std::endl;
//}