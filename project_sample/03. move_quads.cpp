#include <iostream>
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include<cstdlib>
#include<ctime>

GLvoid drawScene ( GLvoid );
GLvoid Reshape( int w , int h );
GLvoid Display ( );
GLvoid MyMouseClick ( int btn , int state , int x , int y );
GLvoid MyMouseMove ( int x , int y );

int r = 1; int g = 1; int b = 1; int f = 1;
//���콺 ��ǥ
int mX1; int mX2; int mY1; int mY2;
//���� ��ǥ
double X1 ; double X2; double Y1; double Y2;

//-----------------------------------------------------------------------main_START
void main ( int argc , char** argv )															//--- ������ ����ϰ� �ݹ��Լ� ���� 
{ 
	//--- ������ �����ϱ�
	glutInit ( &argc , argv );																			// glut �ʱ�ȭ
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA );				// ���÷��� ��� ����
	glutInitWindowPosition ( 0 , 0 );															// �������� ��ġ ����
	glutInitWindowSize ( 500 , 500 );														// �������� ũ�� ����
	glutCreateWindow ( "move_quads" );												// ������ ����( ������ �̸�)

	////--- GLEW �ʱ�ȭ�ϱ�
	//glewExperimental = GL_TRUE;
	//if ( glewInit ( ) != GLEW_OK	)																// glew �ʱ�ȭ
	//{
	//std::cerr << "Unable to initialize GLEW" << std::endl;
	//exit ( EXIT_FAILURE );
	//}
	//else
	//std::cout << "GLEW Initialized\n";

	//glutDisplayFunc ( drawScene );															// ��� �Լ��� ����
	glutDisplayFunc ( Display );																// ��� �Լ��� ����
	glutMouseFunc ( MyMouseClick );
	glutMotionFunc ( MyMouseMove );
	glutReshapeFunc ( Reshape );															// �ٽ� �׸��� �Լ� ����
	glutMainLoop ( );																						// �̺�Ʈ ó�� ���� 
} 
//-----------------------------------------------------------------------main_END

GLvoid drawScene ( )																				//--- �ݹ� �Լ�: �׸��� �ݹ� �Լ� 
{ 
	glClearColor( 0.0f, 0.0f, 1.0f, 1.0f );													// �������� ��blue�� �� ����
	glClear ( GL_COLOR_BUFFER_BIT );												// ������ ������ ��ü�� ĥ�ϱ�
	// �׸��� �κ� ����: �׸��� ���� �κ��� ���⿡ ���Եȴ�.

	glutSwapBuffers ( );																				// ȭ�鿡 ����ϱ�
}

GLvoid Reshape ( int w , int h )																//--- �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ� 
{
	glViewport ( 0 , 0 , w , h );
}

GLvoid Display ( )
{
	glViewport ( 0 , 0 , 500 , 500 );
	glColor4f ( r , g , b , f );
	glClear ( GL_COLOR_BUFFER_BIT );
	
	glBegin ( GL_POLYGON );
	glVertex3f ( X1 , Y1 , 0.0 );
	glVertex3f ( X1 , Y2 , 0.0 );
	glVertex3f ( X2 , Y2 , 0.0 );
	glVertex3f ( X2 , Y1 , 0.0 );
	
	glEnd ( );
	glFlush ( );
}

GLvoid keyboard ( unsigned char key , int x , int y )
{
	int num = 0;
	switch ( key ) {
	case'a':
		if ( num < 5 ) {
			num++;
		}
		else {

		}
		break;
	}
	glutPostRedisplay ( );
}

GLvoid MyMouseClick ( int btn , int state , int x , int y )
{
	if ( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) {
		mX1 = x;
		mY1 = y;
	}
}

GLvoid MyMouseMove ( int x , int y )
{
	mX2 = x;
	mY2 = y;

	X1 = mX1 / 500.0;
	X2 = mX2 / 500.0;
	Y1 = mY1 / 500.0;
	Y2 = mY2 / 500.0;

	glutPostRedisplay ( );
}

GLvoid Mylnit ( ) {
	glClearColor ( 1.0 , 1.0 , 1.0 , 1.0 );
	glMatrixMode ( GL_PROJECTION );
	glLoadldentity ( );

	glOrtho ( 0.0 , 1.0 , 0.0 , 1.0 , -1.0 , 1.0 );
}