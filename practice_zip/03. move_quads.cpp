#include <iostream>
#include <gl/glew.h> //--- 필요한 헤더파일 include
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
//도형 좌표
double X1 = - 0.2 ; double X2 = 0.2; double Y1 = - 0.2; double Y2 = 0.2;

GLfloat mX2 = 0.0 , mY2 = 0.0, mX1 = 0 , mY1 = 0;

//-----------------------------------------------------------------------main_START
void main ( int argc , char** argv )															//--- 윈도우 출력하고 콜백함수 설정 
{ 
	//--- 윈도우 생성하기
	glutInit ( &argc , argv );																			// glut 초기화
	glutInitDisplayMode ( GLUT_RGBA );				// 디스플레이 모드 설정
	glutInitWindowPosition ( 0 , 0 );															// 윈도우의 위치 지정
	glutInitWindowSize ( 500 , 500 );														// 윈도우의 크기 지정
	glutCreateWindow ( "move_quads" );												// 윈도우 생성( 윈도우 이름)


	glutDisplayFunc ( drawScene );															// 출력 함수의 지정
	glutDisplayFunc ( Display );																// 출력 함수의 지정
	//glutMouseFunc ( MyMouse );
	//glutMotionFunc ( MyMouseMove );
	glutReshapeFunc ( Reshape );															// 다시 그리기 함수 지정
	glutMainLoop ( );																						// 이벤트 처리 시작 
} 
//-----------------------------------------------------------------------main_END

GLvoid drawScene ( )																				//--- 콜백 함수: 그리기 콜백 함수 
{ 
	glClearColor( 0.0f, 0.0f, 1.0f, 0.0f );													// 바탕색을 ‘blue’ 로 지정
	glClear ( GL_COLOR_BUFFER_BIT );												// 설정된 색으로 전체를 칠하기
	// 그리기 부분 구현: 그리기 관련 부분이 여기에 포함된다.

	glutSwapBuffers ( );																				// 화면에 출력하기
}

GLvoid Reshape ( int w , int h )																//--- 콜백 함수: 다시 그리기 콜백 함수 
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
	else if ( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
		mX2 = x;
		mY2 = y;

		float Mx , My;

		Mx = mX2 - mX1;
		My = mY2 - mY1;

		X1 = X1 + Mx;
		X2 += Mx;
		Y1 += My;
		Y2 += My;

		Display ( );
	}

	glutPostRedisplay ( );
}

GLvoid MyMouseMove ( int btn, int state,  int x , int y )
{
	if ( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) {
		mX2 = x;
		mY2 = y;

		float Mx , My;

		Mx = mX2 - mX1;
		My = mY2 - mY1;

		X1 += Mx;
		X2 += Mx;
		Y1 += My;
		Y2 += My;
	}

	Display ( );

	glutPostRedisplay ( );
}