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
	int fill [ 10 ] = { 0, };		//���� �ִ� �ڸ� : 1 , ���� ���� �ڸ� : 0
	int space [ 10 ] = { 0, };
	int onoff = 1;

	while ( onoff ) {

		// ��ɾ� �Է�
		cout << "============================================" << endl;
		cout << "�Է� : ";
		cin >> command;
		cout << "============================================" << endl;

		// ����Ʈ �� ���� �Է� ����
		if ( command == '+' ) {

			if ( try_num < 10 ) {
				if ( fill [ try_num ] == 0 ) {
					cout << "x ��ǥ : ";
					cin >> input [ try_num ].x;
					cout << "y ��ǥ : ";
					cin >> input [ try_num ].y;
					cout << "z ��ǥ : ";
					cin >> input [ try_num ].z;

					fill [ try_num ] = 1;
					cout << fill [ try_num ] << endl;
					try_num++;
				}
				else
					cout << "�ش� ��ġ�� �̹� ��ǥ�� �����մϴ�." << endl;
			}
			else
				cout << "����Ʈ�� �� á���ϴ�." << endl;
		}

		// ����Ʈ �� ���� �� ���� ����
		if ( command == '-' ) {
			try_num--;
			if ( fill [ try_num ] == 1 ) {
				input [ try_num ].x = 0;
				input [ try_num ].y = 0;
				input [ try_num ].z = 0;

				fill [ try_num ] = 0;
			}
			else
				cout << "�ش� ��ġ�� �̹� ��ǥ�� �������� �ʽ��ϴ�." << endl;
		}

		// ����Ʈ �� �Ʒ� �Է� ����
		if ( command == 'e' ) {
			if ( fill [ 9 ] == 0 ) {
				for ( int i = try_num; i >0; i-- ) {
					input [ i ] = input [ i-1 ];
				}
				fill [ try_num ] = 1;
				try_num++;

				cout << "x ��ǥ : ";
				cin >> input [ 0 ].x;
				cout << "y ��ǥ : ";
				cin >> input [ 0 ].y;
				cout << "z ��ǥ : ";
				cin >> input [ 0 ].z;
			}
			else
				cout << "����Ʈ�� �� á���ϴ�." << endl;
		}
		 
		// ����Ʈ �� �Ʒ� �� ���� (��ĭ ����) ����
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

		// ����Ʈ�� ���� �� ���� ���� ��� ����
		if ( command == 'l' ) {
			int num = 0;
			for ( int i = 0; i < 10; i++ ) {
				if ( fill [ i ] == 1 ) {
					num++;
				}
			}
			cout << "���� ���� : " << num << endl;
		}

		// ����Ʈ ����
		if ( command == 'c' ) {
			for ( int i = 0; i < 10; i++ ) {
				input [ i ] = { 0,0,0 };
				fill [ i ] = 0;
			}
			try_num = 0;
		}

		// �������� ���� �� �Ÿ��� �ִ� ���� ��ǥ�� ����
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
			cout << "���� �� �Ÿ� : " << space [ save_i ] << endl;
			cout << "��ǥ : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// �������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ�� ����
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
			cout << "���� ����� �Ÿ� : " << space [ save_i ] << endl;
			cout << "��ǥ : " << input [ save_i ].x << " , " << input [ save_i ].y << " , " << input [ save_i ].z << endl;
		}

		// �������� ����
		if ( command == 's' ) {
			int num = 0;
			int save_i = 0;

			for ( int i = 0; i < try_num; i++ ) {
				// ����Ʈ ī�� (��ĭ ����)
				if ( fill [ i ] == 1 ) {
					num++;
					copy [ num ] = input [ i ];
				}
			}
			// �Ÿ� ���
			for ( int i = 0; i < num; i++ ) {
				space [ i ] = ( input [ i ].x * input [ i ].x ) + ( input [ i ].y * input [ i ].y ) + ( input [ i ].z * input [ i ].z );
				copy [ i ].s = space [ i ];
			}
			//sort ( copy [ 0 ] , copy [ num ] );

			for ( int i = 10; i > 0; i-- ) {
				cout << i - 1 << "��°";
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
			cout << i - 1 << "��°" ;
			if ( fill [ i - 1 ] == 1 ) {
				cout <<"  " << input [ i - 1 ].x << "  " << input [ i - 1 ].y << "  " << input [ i - 1 ].z << endl;
			}
			else
				cout << endl;
		}


	}	//while ��
	

	//cout << "x ��ǥ : ";
	//cin >> input [ next ].x ;
	//cout << "y ��ǥ : ";
	//cin >> input [ next ].y;
	//cout << "z ��ǥ : ";
	//cin >> input [ next ].z;

	//cout<<  "��� ��ǥ : " << "x : " << input [ next ].x <<"   y : " << input [ next ].y <<"   z : " << input [ next ].z;

}