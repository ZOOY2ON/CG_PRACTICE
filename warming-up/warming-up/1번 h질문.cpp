#include <iostream>
#include<cstdlib>   //rand(), srand()
#include<ctime>     //time()

using namespace std;

int main ( int argc , char** argv ) {

    char in;				    //���� ��ɾ� �ޱ� ( m���� / a���� / d���� / r��Ľ��ǰ� / t��ġ��� / h4*4 / s��İ��������� / q����)
    int onoff = 1;
    int ONE_copy [ 3 ][ 3 ] = { 0 };
    int TWO_copy [ 3 ][ 3 ] = { 0 };

    srand ( ( unsigned int ) time ( NULL ) );

    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            ONE_copy [ i ][ j ] = rand ( ) % 2;
            TWO_copy [ i ][ j ] = rand ( ) % 2;
        }
    }

    while (onoff )
    {

        int ONE [ 4 ][ 4 ] = { 0 };
        int TWO [ 4 ][ 4 ] = { 0 };
        int M [ 3 ][ 3 ] = { 0 };
        int A [ 3 ][ 3 ] = { 0 };
        int D [ 3 ][ 3 ] = { 0 };
        int ONE_R = 0;
        int TWO_R = 0;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                ONE [ i ][ j ] = ONE_copy [ i ][ j ];
                TWO [ i ][ j ] = TWO_copy [ i ][ j ];
            }
        }

        cout << "---------------------" << endl;
        cout << endl << "ù��° ��Ľ�" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << ONE [ i ][ j ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << endl << "�ι�° ��Ľ�" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << TWO [ i ][ j ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "---------------------" << endl;

        cout << "======================" << endl;
        cout << "�Է� : ";
        cin >> in;

        cout << "======================" << endl;
        //���� ����
        if ( in == 'm' ) {
            //3X3 ��İ� 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    for ( int k = 0; k < 3; k++ ) {
                        M [ i ][ j ] += ONE [ i ][ k ] * TWO [ k ][ j ];
                    }
                }
            }

            cout << "�������" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << M [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout<< endl;
        }

        //���� ����
        else if ( in == 'a' ) {
            //3X3 ��ĵ��� 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                     A [ i ][ j ] += ONE [ i ][ j ] + TWO [ i ][ j ];
                }
            }

            cout << "�������" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << A [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        //���� ����
        else if ( in == 'd' ) {
            //3X3 ��Ļ��� 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                     D [ i ][ j ] += ONE [ i ][ j ] - TWO [ i ][ j ];
                }
            }

            cout << "�������" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << D [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        //��Ľ� ����
        else if ( in == 'r' ) {
            //3X3 ��Ľ� ���ϱ�
            //ù��° ���
            int one_st = ( ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 2 ][ 1 ] * ONE [ 1 ][ 2 ] ) ) * 1;
            //�ι�° ���
            int one_nd = ( ( ONE [ 0 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 2 ][ 1 ] * ONE [ 0 ][ 2 ] ) ) * -1;
            //����° ���
            int one_rd = ( ( ONE [ 0 ][ 1 ] * ONE [ 1 ][ 2 ] ) - ( ONE [ 1 ][ 1 ] * ONE [ 0 ][ 2 ] ) ) * 1;

            cout << endl <<  "ù��° ��Ľ�" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << ONE [ i ][ j ];
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;

            ONE_R = one_st + one_nd + one_rd;
            
            cout << "�� : " << ONE_R << endl;
            
            cout << endl;

            //ù��° ���
            int two_st = ( ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 2 ][ 1 ] * TWO [ 1 ][ 2 ] ) ) * 1;
            //�ι�° ���
            int two_nd = ( ( TWO [ 0 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 2 ][ 1 ] * TWO [ 0 ][ 2 ] ) ) * -1;
            //����° ���
            int two_rd = ( ( TWO [ 0 ][ 1 ] * TWO [ 1 ][ 2 ] ) - ( TWO [ 1 ][ 1 ] * TWO [ 0 ][ 2 ] ) ) * 1;

            cout << endl << "�ι�° ��Ľ�" << endl;

            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << TWO [ i ][ j ];
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;

            TWO_R = two_st + two_nd + two_rd;

            cout << "�� : " << TWO_R << endl;

            cout << endl;
        }

        //��ġ��� ����
        else if ( in == 't' ) {
        //3X3 ��ġ ��Ľ� ���ϱ�
        //ù��° ���
        int one_st = ( ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 1 ][ 2 ] * ONE [ 2 ][ 1 ] ) ) * 1;
        //�ι�° ���
        int one_nd = ( ( ONE [ 1 ][ 0 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 1 ][ 2 ] * ONE [ 2 ][ 0 ] ) ) * -1;
        //����° ���
        int one_rd = ( ( ONE [ 1 ][ 0 ] * ONE [ 2 ][ 1 ] ) - ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 0 ] ) ) * 1;

        cout << endl << "ù��° ��Ľ�" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << ONE [ j ][ i ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        ONE_R = one_st + one_nd + one_rd;

        cout << "�� : " << ONE_R << endl;

        cout << endl;

        //ù��° ���
        int two_st = ( ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 1 ][ 2 ] * TWO [ 2 ][ 1 ] ) ) * 1;
        //�ι�° ���
        int two_nd = ( ( TWO [ 1 ][ 0 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 1 ][ 2 ] * TWO [ 2 ][ 0 ] ) ) * -1;
        //����° ���
        int two_rd = ( ( TWO [ 1 ][ 0 ] * TWO [ 2 ][ 1 ] ) - ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 0 ] ) ) * 1;

        cout << endl << "�ι�° ��Ľ�" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << TWO [ j ][ i ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        TWO_R = two_st + two_nd + two_rd;

        cout << "�� : " << TWO_R << endl;

        cout << endl;
        }

        //4*4 ����
        else if ( in == 'h' ) {
        for ( int i = 0; i < 3; i++ ) {
            ONE [ 3 ][ i ] = 0;
            TWO [ i ][ 3 ] = 0;
        }
        ONE [ 3 ][ 3 ] = 1;
        TWO [ 3 ][ 3 ] = 1;

        cout << endl << "ù��° 4X4 ��Ľ�" << endl;

        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                cout << ONE [ i ][ j ];
                if ( j < 3 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << endl << "�ι�° 4X4 ��Ľ�" << endl;

        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                cout << TWO [ i ][ j ];
                if ( j < 3 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
}

        //��İ� ���⤷��
        else if ( in == 's' ) {

        cout << "��Ľ��� ���� �����մϴ�." << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                ONE_copy [ i ][ j ] = rand ( ) % 2;
                TWO_copy [ i ][ j ] = rand ( ) % 2;
            }
        }
        }

        //���� ����
        else if ( in == 'q' )
            onoff = 0;

        else
            cout << "���� ��ɾ�"<<endl;
    }
   
    return 0;
}