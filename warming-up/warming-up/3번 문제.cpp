#include <iostream>
#include <fstream>	//파일
#include <string>		//get line 사용

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

	ifstream file ( "data_b.txt" );	//파일 열기
	if ( file.is_open ( ) ) {
		while ( getline ( file , line ) ) {
			enter = line;
			while ( onoff ) {
				cout << "입력 : ";
				cin >> input;
				//종료ㅇㅇ
				if ( input == 'q' ) {
					cout << endl << "프로그램을 종료합니다." << endl;
					return 0;
				}

				//전체 뒤집기ㅇㅇ
				if ( input == 'd' ) {

					cout << endl << "=================================================================";
					cout << endl << "문장 :  " << endl;
					cout << line << endl;
					cout << endl << "결과 :  ";

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

				//동일한 간격으로 특수문자 삽입ㅇㅇ
				else if ( input == 'e' ) {
					int num = 0;

					if ( try_e % 2 == 0 ) {
						cout << endl << "간격 입력 : ";
						cin >> num_e;

						cout << endl << "=================================================================";
						cout << endl << "문장 :  " << endl;
						cout << line << endl;
						cout << endl << "결과 :  " << endl;
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
						cout << endl << "문장 :  " << endl;
						cout << line << endl;
						cout << endl << "결과 :  ";
						cout << "--- reset ---" << endl;
						cout << line << endl;
					}
					try_e++;
				}

				//동일한 간격으로 특수문자 삽입ㅇㅇ
				else if ( input == 'E' ) {
					int num = 0;

					if ( try_e % 2 == 0 ) {
						cout << endl << "간격 입력 : ";
						cin >> num_e;

						cout << endl << "=================================================================";
						cout << endl << "문장 :  " << endl;
						cout << line << endl;
						cout << endl << "결과 :  " << endl;

						for ( int i = 0; i < 10; i++ ) {
							enter = line.insert ( num_e*num_e , "@@" );
							num++;
						}
						cout << enter << endl;
					}
					else {
						cout << endl << "=================================================================";
						cout << endl << "문장 :  " << endl;
						cout << line << endl;
						cout << endl << "결과 :  ";
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
			
		file.close ( );		//파일 닫기
	}

	else {
		cout << "Unable to open file";
		return 1;
	}

	return 0;

}