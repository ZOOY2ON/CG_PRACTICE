#include <iostream>
#include<cstdlib>   //rand(), srand()
#include<ctime>     //time()

using namespace std;

int main ( int argc , char** argv ) {

    char in;				    //尻至 誤敬嬢 閤奄 ( m咽質 / a機疾 / d錆疾 / r楳慶縦税葵 / t穿帖楳慶 / h4*4 / s楳慶葵沓棋鹿奄 / q曽戟)
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
        cout << endl << "湛腰属 楳慶縦" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << ONE [ i ][ j ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << endl << "砧腰属 楳慶縦" << endl;

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
        cout << "脊径 : ";
        cin >> in;

        cout << "======================" << endl;
        //咽疾 しし
        if ( in == 'm' ) {
            //3X3 楳慶咽 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    for ( int k = 0; k < 3; k++ ) {
                        M [ i ][ j ] += ONE [ i ][ k ] * TWO [ k ][ j ];
                    }
                }
            }

            cout << "咽疾衣引" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << M [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout<< endl;
        }

        //機疾 しし
        else if ( in == 'a' ) {
            //3X3 楳慶機疾 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                     A [ i ][ j ] += ONE [ i ][ j ] + TWO [ i ][ j ];
                }
            }

            cout << "機疾衣引" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << A [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        //皐奄 しし
        else if ( in == 'd' ) {
            //3X3 楳慶錆疾 
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                     D [ i ][ j ] += ONE [ i ][ j ] - TWO [ i ][ j ];
                }
            }

            cout << "錆疾衣引" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << D [ i ][ j ]    ;
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;
        }

        //楳慶縦 しし
        else if ( in == 'r' ) {
            //3X3 楳慶縦 姥馬奄
            //湛腰属 域至
            int one_st = ( ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 2 ][ 1 ] * ONE [ 1 ][ 2 ] ) ) * 1;
            //砧腰属 域至
            int one_nd = ( ( ONE [ 0 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 2 ][ 1 ] * ONE [ 0 ][ 2 ] ) ) * -1;
            //室腰属 域至
            int one_rd = ( ( ONE [ 0 ][ 1 ] * ONE [ 1 ][ 2 ] ) - ( ONE [ 1 ][ 1 ] * ONE [ 0 ][ 2 ] ) ) * 1;

            cout << endl <<  "湛腰属 楳慶縦" << endl;
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << ONE [ i ][ j ];
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;

            ONE_R = one_st + one_nd + one_rd;
            
            cout << "葵 : " << ONE_R << endl;
            
            cout << endl;

            //湛腰属 域至
            int two_st = ( ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 2 ][ 1 ] * TWO [ 1 ][ 2 ] ) ) * 1;
            //砧腰属 域至
            int two_nd = ( ( TWO [ 0 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 2 ][ 1 ] * TWO [ 0 ][ 2 ] ) ) * -1;
            //室腰属 域至
            int two_rd = ( ( TWO [ 0 ][ 1 ] * TWO [ 1 ][ 2 ] ) - ( TWO [ 1 ][ 1 ] * TWO [ 0 ][ 2 ] ) ) * 1;

            cout << endl << "砧腰属 楳慶縦" << endl;

            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ ) {
                    cout << TWO [ i ][ j ];
                    if ( j < 2 ) cout << " ";
                }
                cout << endl;
            }
            cout << endl;

            TWO_R = two_st + two_nd + two_rd;

            cout << "葵 : " << TWO_R << endl;

            cout << endl;
        }

        //穿帖楳慶 しし
        else if ( in == 't' ) {
        //3X3 穿帖 楳慶縦 姥馬奄
        //湛腰属 域至
        int one_st = ( ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 1 ][ 2 ] * ONE [ 2 ][ 1 ] ) ) * 1;
        //砧腰属 域至
        int one_nd = ( ( ONE [ 1 ][ 0 ] * ONE [ 2 ][ 2 ] ) - ( ONE [ 1 ][ 2 ] * ONE [ 2 ][ 0 ] ) ) * -1;
        //室腰属 域至
        int one_rd = ( ( ONE [ 1 ][ 0 ] * ONE [ 2 ][ 1 ] ) - ( ONE [ 1 ][ 1 ] * ONE [ 2 ][ 0 ] ) ) * 1;

        cout << endl << "湛腰属 楳慶縦" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << ONE [ j ][ i ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        ONE_R = one_st + one_nd + one_rd;

        cout << "葵 : " << ONE_R << endl;

        cout << endl;

        //湛腰属 域至
        int two_st = ( ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 1 ][ 2 ] * TWO [ 2 ][ 1 ] ) ) * 1;
        //砧腰属 域至
        int two_nd = ( ( TWO [ 1 ][ 0 ] * TWO [ 2 ][ 2 ] ) - ( TWO [ 1 ][ 2 ] * TWO [ 2 ][ 0 ] ) ) * -1;
        //室腰属 域至
        int two_rd = ( ( TWO [ 1 ][ 0 ] * TWO [ 2 ][ 1 ] ) - ( TWO [ 1 ][ 1 ] * TWO [ 2 ][ 0 ] ) ) * 1;

        cout << endl << "砧腰属 楳慶縦" << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                cout << TWO [ j ][ i ];
                if ( j < 2 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        TWO_R = two_st + two_nd + two_rd;

        cout << "葵 : " << TWO_R << endl;

        cout << endl;
        }

        //4*4 いい
        else if ( in == 'h' ) {
        for ( int i = 0; i < 3; i++ ) {
            ONE [ 3 ][ i ] = 0;
            TWO [ i ][ 3 ] = 0;
        }
        ONE [ 3 ][ 3 ] = 1;
        TWO [ 3 ][ 3 ] = 1;

        cout << endl << "湛腰属 4X4 楳慶縦" << endl;

        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                cout << ONE [ i ][ j ];
                if ( j < 3 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;

        cout << endl << "砧腰属 4X4 楳慶縦" << endl;

        for ( int i = 0; i < 4; i++ ) {
            for ( int j = 0; j < 4; j++ ) {
                cout << TWO [ i ][ j ];
                if ( j < 3 ) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
}

        //楳慶葵 鹿奄しし
        else if ( in == 's' ) {

        cout << "楳慶縦聖 歯稽 竺舛杯艦陥." << endl;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                ONE_copy [ i ][ j ] = rand ( ) % 2;
                TWO_copy [ i ][ j ] = rand ( ) % 2;
            }
        }
        }

        //曽戟 しし
        else if ( in == 'q' )
            onoff = 0;

        else
            cout << "蒸澗 誤敬嬢"<<endl;
    }
   
    return 0;
}