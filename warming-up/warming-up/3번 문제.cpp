#include <iostream>
#include <fstream>	//����
#include <string>		//get line ���

using namespace std;

int main ( )
{
	char input = { 0, };
	int onoff = 1;
	int try_d = 0;
	int try_e = 0;
	int num_e = 0;
	int try_f = 0;

	string line;
	string enter;

	ifstream file ( "data_b.txt" );	//���� ����
	if ( file.is_open ( ) ) {
		while ( getline ( file , line ) ) {
			enter = line;
			while ( onoff ) {
				cout << "�Է� : ";
				cin >> input;
				//���ᤷ��
				if ( input == 'q' ) {
					cout << endl << "���α׷��� �����մϴ�." << endl;
					return 0;
				}

				//��ü �����⤷��
				if ( input == 'd' ) {

					cout << endl << "=================================================================";
					cout << endl << "���� :  " << endl;
					cout << line << endl;
					cout << endl << "��� :  ";

					if ( try_d % 2 == 0 ) {
						for ( int i = 0; i < line.length ( ); i++ ) {
							enter [ i ] = line [ line.length ( ) - ( i + 1 ) ];
						}
						cout << endl << enter << endl;
					}
					else {
						cout << "--- reset ---" << endl;
						cout << line << endl;
					}
					try_d++;
				}

				//������ �������� Ư������ ���Ԥ���
				else if ( input == 'e' ) {
					int num = 0;

					if ( try_e % 2 == 0 ) {
						cout << endl << "���� �Է� : ";
						cin >> num_e;

						cout << endl << "=================================================================";
						cout << endl << "���� :  " << endl;
						cout << line << endl;
						cout << endl << "��� :  " << endl;
						for ( int i = 0; i < line.length ( ); i++ ) {
							//enter [ i ] = line [ line.length ( ) - ( i + 1 ) ];
							cout << line [ i ] ;
							if ( i == num+num_e-1 ) {
								cout << "@@";
								num = i+1;
							}
						}
					}
					else {
						cout << endl << "=================================================================";
						cout << endl << "���� :  " << endl;
						cout << line << endl;
						cout << endl << "��� :  ";
						cout << "--- reset ---" << endl;
						cout << line << endl;
					}
					try_e++;
				}

				//������ �������� Ư������ ���Ԥ���
				else if ( input == 'E' ) {
					int num = 0;

					if ( try_e % 2 == 0 ) {
						cout << endl << "���� �Է� : ";
						cin >> num_e;

						cout << endl << "=================================================================";
						cout << endl << "���� :  " << endl;
						cout << line << endl;
						cout << endl << "��� :  " << endl;

						for ( int i = 0; i < 10; i++ ) {
							enter = line.insert ( num_e*num_e , "@@" );
							num++;
						}
						cout << enter << endl;
					}
					else {
						cout << endl << "=================================================================";
						cout << endl << "���� :  " << endl;
						cout << line << endl;
						cout << endl << "��� :  ";
						cout << "--- reset ---" << endl;
						cout << line << endl;
					}
					try_e++;
				}

				else if ( input == 'f' ) {

				}
				else if ( input == 'g' ) {

				}
				else if ( input == 'h' ) {

				}

				else {
					cout << endl << "not found command" << endl;
				}
				cout << endl << "=================================================================" << endl;
			}
		}
			
		file.close ( );		//���� �ݱ�
	}

	else {
		cout << "Unable to open file";
		return 1;
	}

	return 0;

}