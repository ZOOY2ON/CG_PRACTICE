#include<iostream>
#include<cstdlib>   //rand(), srand()
#include<ctime>     //time()

#define MAX 29

using namespace std;

int main ( ) {

	srand ( ( unsigned int ) time ( NULL ) );

	int road = 0;
	int map [ 29 ][ 29 ] = { 0, };
	int a_map [ 29 ] = { 0, };
	int d_map [ 29 ] = { 0, };

	// 방향 결정 랜덤
	int control = 0;
	// 이동 칸수 랜덤
	int move = 0;

	int x = 0;
	int y = 0;

	int onoff=1;
	char command;

	cout << endl << "====================================================== road find ======================================================" << endl << endl;

	//시작


	while ( onoff ) {
		cout << "============================================" << endl;
		cout << "입력 : "; 
		cin >> command;
		cout << "============================================" << endl;

		// 경로 만들기
		if ( command == 'r' ) {
			int w = 1;
			while ( w ) {
				if ( map [ 29 ][ 29 ] == 0 ) {
					map [ 0 ][ 0 ] = 1;
					//경로 만들기
					control = rand ( ) % 4 + 1;
					move = rand ( ) % 10;

					//오른쪽 이동
					if ( control == 1 ) {
						if ( x + move < 30 ) {
							for ( int i = 0; i < move; i++ ) {
								road++;
								//if ( x++ != 0 || y !=0 ) {
								map [ y ][ x++ ] = road;
								//}
							}
						}
						else if ( x + move > 29 ) {
							for ( int i = x; i < 29; i++ ) {
								road++;
								map [ y ][ x++ ] = road;
							}
						}
					} //오른쪽 이동

					//왼쪽 이동
					else if ( control == 2 ) {
						if ( x - move > 0 ) {
							for ( int i = 0; i < move; i++ ) {
								road++;
								//if ( x-- != 0 || y != 0 ) {
								map [ y ][ x-- ] = road;
								//}
							}
						}
						else if ( x - move < 1 ) {
							for ( int i = 0; i < x; i++ ) {
								road++;
								map [ y ][ x-- ] = road;
							}
						}
					} //왼쪽 이동

					//위쪽 이동
					else if ( control == 3 ) {
						if ( y - move > 0 ) {
							for ( int i = 0; i < move; i++ ) {
								road++;
								//if ( x != 0 || y-- != 0 ) {
								map [ y-- ][ x ] = road;
								//}
							}
						}
						else if ( y - move < 0 ) {
							for ( int i = 0; i < y; i++ ) {
								road++;
								//if ( x != 0 || y-- != 0 ) {
								map [ y-- ][ x ] = road;
								//}
							}
						}
					} //위쪽 이동

					//아래쪽 이동
					else if ( control == 4 ) {
						if ( y + move < 30 ) {
							for ( int i = 0; i < move; i++ ) {
								road++;
								//if ( x != 0 || y++ != 0 ) {
								map [ y++ ][ x ] = road;
								//}
							}
						}
						else if ( y + move > 29 ) {
							for ( int i = y; i < 29; i++ ) {
								road++;
								map [ y++ ][ x ] = road;
							}
						}
					} //아래쪽 이동
				}
				else if ( map [ 29 ][ 29 ] != 0 ) {
					for ( int i = 0; i < 29; i++ ) {
						for ( int j = 0; j < 29; j++ ) {
							cout.width ( 5 );
							cout << right << map [ i ][ j ];
						}
						cout << endl << endl;
					}
					w = 0;
				}
			}
		}
		
		// 좌측으로 옮기기
		else if ( command == 'a' ) {
			for ( int i = 0; i < 29; i++ ) {
				a_map [ i ] = map [ i ][ 0 ];
				for ( int j = 0; j < 29; j++ ) {
					map [ i ][ j ] = map [ i ][ j + 1 ];
					if ( i == 28 ) {
						map [ j ][ 28 ] = a_map [ j ];

						cout << endl << j << "번째  " << a_map [ j ] << endl;
					}
					cout.width ( 5 );
					cout << right << map [ i ][ j ];
				}
				cout << endl << endl;
			}
		}

		// 우측으로 옮기기
		else if ( command == 'd' ) {
			for ( int i = 30; i > 0; i-- ) {
				d_map [ i ] = map [ i ][ 28 ];
				for ( int j = 29; i > 0; j-- ) {
					if ( i == 0 ) {
						map [ j ][ 28 ] = d_map [ j ];

						cout << endl << j << "번째  " << d_map [ j ] << endl;
					}
					cout.width ( 5 );
					cout << right << map [ i ][ j ];
				}
				cout << endl << endl;
			}
		}
			

	 }  //while 끝
}