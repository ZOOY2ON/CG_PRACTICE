#include <iostream>
#include <fstream>	//����
#include <string>		//get line ���

using namespace std;

int main ( )
{
	int word = 0;				//�ܾ� ����
	int num = 0;				//���� ����
	int cap = 0;				//�빮�� ����
	int check_n = 0;		//���� ���� üũ

	string line;
	string name;

	ifstream file ( "data.txt" );	//���� ����
	if ( file.is_open ( ) ) {
		while ( getline ( file , line ) ) {
			int text = line.length ( );

			// �ܾ� ����
			for ( int i = 0; i < text; i++ ) {
				if ( line [ i ] == ' ' )
					word++;
				else if ( line [ i ] == '\n' )
					word++;
				else
					continue;
			}

			// ���� ����
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

			//while�� ���� ������ ���� ������ -> 
			//���� ���������� ������

			//�빮�� ����
			for ( int i = 0; i < text; i++ ) {
				if ( line [ i ] == ' ' || line [ i ] == '\n' ) {
					if ( line [ i + 1 ] > 64 && line [ i + 1 ] < 91 )
						cap++;
				}
				else
					continue;
			}
		}
		file.close ( );		//���� �ݱ�
	}

	else {
		cout << "Unable to open file";
		return 1;
	}

	cout << endl << "�ܾ� ���� : " << word << endl;
	cout << endl << "�빮�� ���� : " << cap << endl;
	cout << endl << "���� ���� : " << num << endl;

	return 0;

	// �ܾ� ���� ���� : 45

}