#include<iostream>
using namespace std;
char grid[105][105];
int m,n;
void DFS( int x , int y ){

    if( x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '@'){
            grid[x][y] = '*';

            for( int i = -1 ; i < 2 ; i++ )
                for( int j = -1 ; j < 2 ; j++ )
                    DFS( x+i , y+j );
    }

}

int main(){

    int counter;

    while( cin >> m >> n && !( m == 0 && n == 0 ) ){
        counter = 0;
        for( int i = 0 ; i < m ; i ++ )
            for( int j = 0 ; j < n ; j++ )
                cin >> grid[i][j];
        for( int i = 0 ; i < m ; i ++ )
            for( int j = 0 ; j < n ; j++ )
                if( grid[i][j] == '@' ){
                    DFS( i , j );
                    counter++;
                }
        cout << counter << endl;

    }
    return 0;
}
