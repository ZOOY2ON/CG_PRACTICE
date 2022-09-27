#include<iostream>
#include<algorithm>

//#define next 10

using namespace std;

typedef struct Dot {
	int x;
	int y;
	int z;
	int s;
}Dot;

int main ( ) {

	Dot input [ 10 ];
	Dot copy [ 10 ];
	char command;
	int try_num = 0;
	int fill [ 10 ] = { 0, };		//값이 있는 자리 : 1 , 값이 없는 자리 : 0
	int space [ 10 ] = { 0, };
	int onoff = 1;

	while ( onoff ) {

		// 명령어 입력
		cout << "============================================" << endl;
		cout << "입력 : ";
		cin >> command;
		cout << "============================================" << endl;

		// 리스트 맨 위에 입력 ㅇㅇ
		if ( command == '+' ) {

			if ( try_num < 10 ) {
				if ( fill [ try_num ] == 0 ) {
					cout << "x 좌표 : ";
					cin >> input [ try_num ].x;
					cout << "y 좌표 : ";
					cin >> input [ try_num ].y;
					cout << "z 좌표 : ";
					cin >> input [ try_num ].z;

					fill [ try_num ] = 1;
					cout << fill [ try_num ] << endl;
					try_num++;
				}
				else
					cout << "해당 위치에 이미 좌표가 존재합니다." << endl;
			}
			else
				cout << "리스트가 꽉 찼습니다." << endl;
		}

		// 리스트 맨 위에 값 삭제 ㅇㅇ
		if ( command == '-' ) {
			try_num--;
			if ( fill [ try_num ] == 1 ) {
				input [ try_num ].x = 0;
				input [ try_num ].y = 0;
				input [ try_num ].z = 0;

				fill [ try_num ] = 0;
			}
			else
				cout << "해당 위치에 이미 좌표가 존재하지 않습니다." << endl;
		}

		// 리스트 맨 아래 입력 ㅇㅇ
		if ( command == 'e' ) {
			if ( fill [ 9 ] == 0 ) {
				for ( int i = try_num; i >0; i-- ) {
					input [ i ] = input [ i-1 ];
				}
				fill [ try_num ] = 1;
				try_num++;

				cout << "x 좌표 : ";
				cin >> input [ 0 ].x;
				cout << "y 좌표 : ";
				cin >> input [ 0 ].y;
				cout << "z 좌표 : ";
				cin >> input [ 0 ].z;
			}
			else
				cout << "리스트가 꽉 찼습니다." << endl;
		}
		 
		// 리스트 맨 아래 값 삭제 (빈칸 유지) ㅇㅇ
		if ( command == 'd' ) {
			for ( int i = 0; i < try_num; i++ ) {
				if ( fill [ i ] == 1 ) {
					input [ i ].x = 0;
					input [ i ].y = 0;
					input [ i ].z = 0;

					fill [ i ] = 0;
					break;
				}
				else
					continue;
			}
		}

		// 리스트에 저장 된 점의 갯수 출력 ㅇㅇ
		if ( command == 'l' ) {
			int num = 0;
			for ( int i = 0; i < 10; i++ ) {
				if ( fill [ i ] == 1 ) {
					num++;
				}
			}
			cout << "점의 개수 : " << num << endl;
		}

		// 리스트 비우기
		if ( command == 'c' ) {
			for ( int i = 0; i < 10; i++ ) {
				input [ i ] = { 0,0,0 };
				fill [ i ] = 0;
			}
			try_num = 0;
		}

		// 원점에서 가장 먼 거리에 있는 점의 좌표값 ㅇㅇ
		if ( command == 'm' ) {
			int save_i = 0;

			for ( int i = 0; i < try_num; i++ ) {
				if ( fill [ i ] == 1 ) {
					space [ i ] = ( input [ i ].x * input [ i ].x ) + ( input [ i ].y * input [ i ].y ) + ( input [ i ].z * input [ i ].z );
					if ( i > 0 ) {
						if ( space [ i ] > space [ save_i ] ) {
							save_i = i;
						}
						else
							continue;
					}
					else {
						save_i = i;
					}
				}
			}
			cout << "가장 먼 거리 : " << space [ save_i ] << endl;
			cout << "좌표 : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// 원점에서 가장 가까운 거리에 있는 점의 좌표값 ㅇㅇ
		if ( command == 'n' ) {
			int save_i = 0;

			for ( int i = 0; i < try_num; i++ ) {
				if ( fill [ i ] == 1 ) {
					space [ i ] = ( input [ i ].x * input [ i ].x ) + ( input [ i ].y * input [ i ].y ) + ( input [ i ].z * input [ i ].z );
					if ( i > 0 ) {
						if ( space [ i ] < space [ i - 1 ] ) {
							save_i = i;
						}
						else
							continue;
					}
					else {
						save_i = i;
					}
				}
			}
			cout << "가장 가까운 거리 : " << space [ save_i ] << endl;
			cout << "좌표 : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// 오름차순 정렬
		if ( command == 's' ) {
			int num = 0;
			int save_i = 0;

			for ( int i = 0; i < try_num; i++ ) {
				// 리스트 카피 (빈칸 없이)
				if ( fill [ i ] == 1 ) {
					num++;
					copy [ num ] = input [ i ];
				}
			}
			// 거리 계산
			for ( int i = 0; i < num; i++ ) {
				space [ i ] = ( input [ i ].x * input [ i ].x ) + ( input [ i ].y * input [ i ].y ) + ( input [ i ].z * input [ i ].z );
				copy [ i ].s = space [ i ];
			}
			//sort ( copy [ 0 ] , copy [ num ] );

			for ( int i = 10; i > 0; i-- ) {
				cout << i - 1 << "번째";
				if ( fill [ i - 1 ] == 1 ) {
					cout << "  " << copy [ i - 1 ].x << "  " << copy [ i - 1 ].y << "  " << copy [ i - 1 ].z << endl;
				}
				else
					cout << endl;
			}
		}

		if ( command == 'q' ) {
			return 0;
		}

		for ( int i = 10; i > 0; i-- ) {
			cout << i - 1 << "번째" ;
			if ( fill [ i - 1 ] == 1 ) {
				cout <<"  " << input [ i - 1 ].x << "  " << input [ i - 1 ].y << "  " << input [ i - 1 ].z << endl;
			}
			else
				cout << endl;
		}


	}	//while 끝
	

	//cout << "x 좌표 : ";
	//cin >> input [ next ].x ;
	//cout << "y 좌표 : ";
	//cin >> input [ next ].y;
	//cout << "z 좌표 : ";
	//cin >> input [ next ].z;

	//cout<<  "출력 좌표 : " << "x : " << input [ next ].x <<"   y : " << input [ next ].y <<"   z : " << input [ next ].z;

}