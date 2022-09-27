#include <iostream>
#include<cstdlib>   //rand(), srand()
#include<ctime>     //time()

using namespace std;

int main ( )
{
	int left_st , top_st , rigth_st , bottom_st;		//left_st : x1, top_st : y1, rigth_st : x2, bottom_st : y2
	int left_nd , top_nd , rigth_nd , bottom_nd;	//left_nd : x3, top_nd : y3, rigth_nd : x4, bottom_nd : y4

	srand ( ( unsigned int ) time ( NULL ) );

	for ( int i = 0; i < 10; i++ ) {
		left_st = rand ( ) % 201 + 600;						// 600~800 범위의 난수 생성 * rand( )% '마지막 값 - 시작 값 + 1' + '시작 값'
		cout << left_st << endl;
	}

}