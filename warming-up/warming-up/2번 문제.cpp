#include <iostream>
#include <fstream>	//파일
#include <string>		//get line 사용

using namespace std;

int main ( )
{
	int word = 0;				//단어 개수
	int num = 0;				//숫자 개수
	int cap = 0;				//대문자 개수
	int check_n = 0;		//숫자 연속 체크

	string line;
	string name;

	ifstream file ( "data.txt" );	//파일 열기
	if ( file.is_open ( ) ) {
		while ( getline ( file , line ) ) {
			int text = line.length ( );

			// 단어 개수
			for ( int i = 0; i < text; i++ ) {
				if ( line [ i ] == ' ' )
					word++;
				else if ( line [ i ] == '\n' )
					word++;
				else
					continue;
			}

			// 숫자 개수
			for ( int i = 0; i < text; i++ ) {
				if ( line [ i ] > 47 && line [ i ] < 58 ) {
					check_n++;

					//if ( line [ i + 1 ] < 47 || line [ i + 1 ]>58 ) {
					//	num--;
					//}
					//else if ( line [ i - 1 ] < 47 || line [ i - 1 ] >58 )
					//	num--;
				}
				else if ( line [ i ] == 'n' || line [ i ] == '\n' ) {
					if ( check_n > 0 ) {
						check_n = 0;
						num++;
					}
				}
			}

			//while로 엔터 만날때 끝내 버리기 -> 
			//띄어씌기 ㅈ기준으로 돌리기

			//대문자 개수
			for ( int i = 0; i < text; i++ ) {
				if ( line [ i ] == ' ' || line [ i ] == '\n' ) {
					if ( line [ i + 1 ] > 64 && line [ i + 1 ] < 91 )
						cap++;
				}
				else
					continue;
			}
		}
		file.close ( );		//파일 닫기
	}

	else {
		cout << "Unable to open file";
		return 1;
	}

	cout << endl << "단어 개수 : " << word << endl;
	cout << endl << "대문자 개수 : " << cap << endl;
	cout << endl << "숫자 개수 : " << num << endl;

	return 0;

	// 단어 개수 세기 : 45

}