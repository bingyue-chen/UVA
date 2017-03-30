#include<iostream>
#include<algorithm>

using namespace std;
char grid[105][105];
int m,n;
struct data{
    char c;
    int x;
};
bool com( const data& A , const data& B ){
    if( A.x == B.x )
        return A.c < B.c;
    else
        return A.x > B.x;
}

void DFS( int x , int y , char c ){

    if( x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == c ){
            grid[x][y] = '*';

            DFS( x+1 , y , c );
            DFS( x-1 , y , c );
            DFS( x , y+1 , c );
            DFS( x , y-1 , c );
    }

}

int main(){

    int counter;
    data datamap[30];
    cin >> counter;
    int snow;
    for( snow = 1 ; snow <= counter ; snow++ ){
        cin >> m >> n;
            for( int i = 0 ; i < 30 ; i++ ){
                datamap[i].c = ' ';
                datamap[i].x = 0;
            }
            int temp = 0;
            for( int i = 0 ; i < m ; i ++ )
                for( int j = 0 ; j < n ; j++ ){
                    cin >> grid[i][j];
                    int l = 0,flag = false;
                    for( l = 0 ; l < temp && !flag ; l++ )
                        if( datamap[l].c == grid[i][j] ) flag = true;
                    if( !flag )
                        datamap[temp++].c = grid[i][j];
                }

            for( int i = 0 ; i < m ; i ++ )
                for( int j = 0 ; j < n ; j++ )
                    if( grid[i][j] != '*' ){
                        int l = 0;
                        for( l = 0 ; l < temp ; l++ )
                            if( datamap[l].c == grid[i][j] ){
                                datamap[l].x = datamap[l].x+1;
                                break;
                            }
                        DFS( i , j , grid[i][j] );
                    }
            sort( datamap , datamap+temp , com );
            cout << "World #" << snow << endl;
            for( int i = 0 ; i < temp ; i++ )
                cout << datamap[i].c << ": " << datamap[i].x << endl;

    }
    return 0;
}

