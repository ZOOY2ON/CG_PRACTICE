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
	int fill [ 10 ] = { 0, };		//葵戚 赤澗 切軒 : 1 , 葵戚 蒸澗 切軒 : 0
	int space [ 10 ] = { 0, };
	int onoff = 1;

	while ( onoff ) {

		// 誤敬嬢 脊径
		cout << "============================================" << endl;
		cout << "脊径 : ";
		cin >> command;
		cout << "============================================" << endl;

		// 軒什闘 固 是拭 脊径 しし
		if ( command == '+' ) {

			if ( try_num < 10 ) {
				if ( fill [ try_num ] == 0 ) {
					cout << "x 疎妊 : ";
					cin >> input [ try_num ].x;
					cout << "y 疎妊 : ";
					cin >> input [ try_num ].y;
					cout << "z 疎妊 : ";
					cin >> input [ try_num ].z;

					fill [ try_num ] = 1;
					cout << fill [ try_num ] << endl;
					try_num++;
				}
				else
					cout << "背雁 是帖拭 戚耕 疎妊亜 糎仙杯艦陥." << endl;
			}
			else
				cout << "軒什闘亜 暇 叩柔艦陥." << endl;
		}

		// 軒什闘 固 是拭 葵 肢薦 しし
		if ( command == '-' ) {
			try_num--;
			if ( fill [ try_num ] == 1 ) {
				input [ try_num ].x = 0;
				input [ try_num ].y = 0;
				input [ try_num ].z = 0;

				fill [ try_num ] = 0;
			}
			else
				cout << "背雁 是帖拭 戚耕 疎妊亜 糎仙馬走 省柔艦陥." << endl;
		}

		// 軒什闘 固 焼掘 脊径 しし
		if ( command == 'e' ) {
			if ( fill [ 9 ] == 0 ) {
				for ( int i = try_num; i >0; i-- ) {
					input [ i ] = input [ i-1 ];
				}
				fill [ try_num ] = 1;
				try_num++;

				cout << "x 疎妊 : ";
				cin >> input [ 0 ].x;
				cout << "y 疎妊 : ";
				cin >> input [ 0 ].y;
				cout << "z 疎妊 : ";
				cin >> input [ 0 ].z;
			}
			else
				cout << "軒什闘亜 暇 叩柔艦陥." << endl;
		}
		 
		// 軒什闘 固 焼掘 葵 肢薦 (朔牒 政走) しし
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

		// 軒什闘拭 煽舌 吉 繊税 姐呪 窒径 しし
		if ( command == 'l' ) {
			int num = 0;
			for ( int i = 0; i < 10; i++ ) {
				if ( fill [ i ] == 1 ) {
					num++;
				}
			}
			cout << "繊税 鯵呪 : " << num << endl;
		}

		// 軒什闘 搾酔奄
		if ( command == 'c' ) {
			for ( int i = 0; i < 10; i++ ) {
				input [ i ] = { 0,0,0 };
				fill [ i ] = 0;
			}
			try_num = 0;
		}

		// 据繊拭辞 亜舌 胡 暗軒拭 赤澗 繊税 疎妊葵 しし
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
			cout << "亜舌 胡 暗軒 : " << space [ save_i ] << endl;
			cout << "疎妊 : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// 据繊拭辞 亜舌 亜猿錘 暗軒拭 赤澗 繊税 疎妊葵 しし
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
			cout << "亜舌 亜猿錘 暗軒 : " << space [ save_i ] << endl;
			cout << "疎妊 : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// 神硯託授 舛慶
		if ( command == 's' ) {
			int num = 0;
			int save_i = 0;

			for ( int i = 0; i < try_num; i++ ) {
				// 軒什闘 朝杷 (朔牒 蒸戚)
				if ( fill [ i ] == 1 ) {
					num++;
					copy [ num ] = input [ i ];
				}
			}
			// 暗軒 域至
			for ( int i = 0; i < num; i++ ) {
				space [ i ] = ( input [ i ].x * input [ i ].x ) + ( input [ i ].y * input [ i ].y ) + ( input [ i ].z * input [ i ].z );
				copy [ i ].s = space [ i ];
			}
			//sort ( copy [ 0 ] , copy [ num ] );

			for ( int i = 10; i > 0; i-- ) {
				cout << i - 1 << "腰属";
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
			cout << i - 1 << "腰属" ;
			if ( fill [ i - 1 ] == 1 ) {
				cout <<"  " << input [ i - 1 ].x << "  " << input [ i - 1 ].y << "  " << input [ i - 1 ].z << endl;
			}
			else
				cout << endl;
		}


	}	//while 魁
	

	//cout << "x 疎妊 : ";
	//cin >> input [ next ].x ;
	//cout << "y 疎妊 : ";
	//cin >> input [ next ].y;
	//cout << "z 疎妊 : ";
	//cin >> input [ next ].z;

	//cout<<  "窒径 疎妊 : " << "x : " << input [ next ].x <<"   y : " << input [ next ].y <<"   z : " << input [ next ].z;

}