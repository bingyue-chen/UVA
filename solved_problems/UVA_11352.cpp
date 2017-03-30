#include <iostream>
#include <cstdlib>
#define MAX 105

using namespace std;
int m,n,t,step,ct,ax,ay,bx,by;
char forest[MAX][MAX];

void mark( int x , int y ){
    int mx[8]={-1,1,-2,2,-2,2,-1,1};
    int my[8]={-2,-2,-1,-1,1,1,2,2};

    for( int i = 0 ; i < 8 ; i++ ){
        for( int j = 0 ; j < 8 ; j ++ ){

            if( forest[ x + mx[i] ][ y + my[i] ] == '.' &&
                x + mx[i] >= 0 &&
                x + mx[i] < m &&
                y + my[j] >= 0 &&
                my[j] < n
                ){
                    forest[ x + mx[i] ][ y + my[i] ] = '*';
                }

        }
    }

}

int direction( int x , int y ){

    int dx = bx - x;
    int dy = by - y;

    if( dx >= 0 && dy >=0 )
        return 1;
    else if( dx < 0 && dy < 0 )
        return 3;
    else if( x < 0 )
        return 2;
    else
        return 4;

}


void king( int x , int y , int sum ){
        ct++;
        /*cout << endl;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j ++ ){
                cout << forest[i][j];
            }
            cout << endl;
        }
        system("PAUSE");*/

    if( forest[x][y] == 'B' && ( step == 0 || step > sum ) )
        step = sum;
    else if( forest[x][y] == '.' && ( step == 0 || sum < step - 1 ) ){

        forest[x][y] = '-';

        int d = direction( x , y );

        if( d == 3 ){

            for( int i = -1 ; i <= 1 ; i++ ){
                for( int j = -1 ; j <= 1 ; j++ ){
                    if( x + i >= 0 &&
                        x + i < m  &&
                        y + j >= 0 &&
                        y + j < n
                        )
                            king( x + i , y + j , sum + 1 );
                }
            }

        }
        else if( d == 1 ){
            for( int i = 1 ; i >= -1 ; i-- ){
                for( int j = 1 ; j >= -1 ; j-- ){
                    if( x + i >= 0 &&
                        x + i < m  &&
                        y + j >= 0 &&
                        y + j < n
                        )
                            king( x + i , y + j , sum + 1 );
                }
            }
        }
        else if( d == 4 ){
            for( int i = 1 ; i >= -1 ; i-- ){
                for( int j = -1 ; j <= 1 ; j++ ){
                    if( x + i >= 0 &&
                        x + i < m  &&
                        y + j >= 0 &&
                        y + j < n
                        )
                            king( x + i , y + j , sum + 1 );
                }
            }
        }
        else{
            for( int i = -1 ; i <= 1 ; i++ ){
                for( int j = 1 ; j >= -1 ; j-- ){
                    if( x + i >= 0 &&
                        x + i < m  &&
                        y + j >= 0 &&
                        y + j < n
                        )
                            king( x + i , y + j , sum + 1 );
                }
            }
        }

        forest[x][y] = '.';

    }

}

int main(){

    cin >> t;

    while( t-- ){

        cin >> m >> n;

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j ++ )
                cin >> forest[i][j];
        }

        /*cout << endl;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j ++ ){
                cout << forest[i][j];
            }
            cout << endl;
        }*/

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j ++ )
                if( forest[i][j] == 'Z' )
                    mark( i , j );
                else if( forest[i][j] == 'A' ){
                    ax = i;
                    ay = j;
                }
                else if( forest[i][j] == 'B' ){
                    bx = i;
                    bx = j;
                }
        }

        /*cout << endl;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j ++ ){
                cout << forest[i][j];
            }
            cout << endl;
        }*/

        step = ct = 0;
        forest[ax][ay] = '.';
        king( ax , ay , 0 );

        if( step == 0 ){
            cout << "King Peter, you can't go now!" << endl;
        }
        else{
            cout <<  "Minimal possible length of a trip is " << step << endl;
        }
        cout << ct << endl;
    }

    return 0;
}

