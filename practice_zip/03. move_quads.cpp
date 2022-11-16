#include <iostream>
#include <gl/glew.h> //--- �ʿ��� ������� include
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>

#include<cstdlib>
#include<ctime>

GLvoid drawScene ( GLvoid );
GLvoid Reshape( int w , int h );
GLvoid Display ( );
GLvoid MyMouse ( int btn , int state , int x , int y );
GLvoid MyMouseMove ( int x , int y );

int r = 1; int g = 0; int b = 0; int f = 0;
//���� ��ǥ
double X1 = - 0.2 ; double X2 = 0.2; double Y1 = - 0.2; double Y2 = 0.2;

GLfloat mX2 = 0.0 , mY2 = 0.0, mX1 = 0 , mY1 = 0;

//-----------------------------------------------------------------------main_START
void main ( int argc , char** argv )															//--- ������ ����ϰ� �ݹ��Լ� ���� 
{ 
	//--- ������ �����ϱ�
	glutInit ( &argc , argv );																			// glut �ʱ�ȭ
	glutInitDisplayMode ( GLUT_RGBA );												// ���÷��� ��� ����
	glutInitWindowPosition ( 0 , 0 );															// �������� ��ġ ����
	glutInitWindowSize ( 500 , 500 );														// �������� ũ�� ����
	glutCreateWindow ( "move_quads" );												// ������ ����( ������ �̸�)


	glutDisplayFunc ( drawScene );															// ��� �Լ��� ����
	glutDisplayFunc ( Display );																// ��� �Լ��� ����
	glutMouseFunc ( MyMouse );
	glutMotionFunc ( MyMouseMove );
	glutReshapeFunc ( Reshape );															// �ٽ� �׸��� �Լ� ����
	glutMainLoop ( );																						// �̺�Ʈ ó�� ���� 
} 
//-----------------------------------------------------------------------main_END

GLvoid drawScene ( )																				//--- �ݹ� �Լ�: �׸��� �ݹ� �Լ� 
{ 
	glClearColor( 0.0f, 0.0f, 1.0f, 0.0f );													// �������� ��blue�� �� ����
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
	//glViewport ( 0 , 0 , 500 , 500 );
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

GLvoid MyMouse ( int btn , int state , int x , int y )
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

	float cg_x , cg_y;

	cg_x = ( ( ( mX2 - 250 ) / 250 ) - ( ( mX1 - 250 ) / 250 ) );
	cg_y = ( ( ( mY1 - 250 ) / 250 ) - ( ( mY2 - 250 ) / 250 ) );

	X1 += cg_x;
	X2 += cg_x;
	Y1 += cg_y;
	Y2 += cg_y;

	Display ( );

	//std::cout << X1 << X2 << Y1 << Y2 << std::endl;

	glutPostRedisplay ( );
}