#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ( void )
{
	int num_one [ 9 ] = {0,};
	int num_two [ 9 ] = { 0, };
	int random = 0;
	srand ( time ( NULL ) );
	char a;										//���� ��ɾ� �ޱ� ( m���� / a���� / d���� / r��Ľ��ǰ� / t��ġ��� / h4*4 / s��İ��������� / q����)

	for ( int i = 0; i < 10; i++ ) {		
		random = rand ( ) % 9;		//0~8 ������ ���� ����

		for ( int j = 0; j < 10; j++ ) {
			if ( random == 0 )
				num_one [ j ] = 1;
			else if ( random % 2 == 0 )
				num_one [ j ] = 1;
			else
				num_one [ j ] = 1;
		}
	} // ù��° ���

	for ( int i = 0; i < 10; i++ ) {
		random = rand ( ) % 9;		//0~8 ������ ���� ����

		for ( int j = 0; j < 10; j++ ) {
			if ( random == 0 )
				num_two [ j ] = 2;
			else if ( random / 2 == 0 )
				num_two [ j ] = 0;
			else
				num_two [ j ] = 1;
		}
	} // �ι�° ���
	
	//---------------------���
	printf ( "ù��° ���\n" );
	printf ( "%d %d %d\n" , num_one [ 1 ] , num_one [ 2 ] , num_one [ 3 ] );
	printf ( "%d %d %d\n" , num_one [ 4 ] , num_one [ 5 ] , num_one [ 6 ] );
	printf ( "%d %d %d\n" , num_one [ 7 ] , num_one [ 8 ] , num_one [ 9 ] );

	//---------------------����
	

}