#include <iostream>
#include <queue>

using namespace std;

int color[105][105];

int bfs( int n , int n1 , int n2 , int n3 ){

    int i,j,d[105][105],newi,newj;
    queue<int> myqueue;

    myqueue.push( n1 );
    myqueue.push( n2 );

    for( i = 0 ; i < 105 ; i++ )
        for( j = 0 ; j < 105 ; j++ )
            d[i][j] = 0;

    while( !myqueue.empty() ){

         i = myqueue.front();
         myqueue.pop();

         j = myqueue.front();
         myqueue.pop();

         if( i == n3 || j == n3 )
            return d[i][j];

         if( color[i][j] != 0 ){

             newi = color[i][j];
             newj = j;

             if( d[newi][newj] == 0 ){
                d[newi][newj] = d[i][j] + 1;
                myqueue.push( newi );
                myqueue.push( newj );
             }
         }

         if( color[j][i] != 0 ){

             newi = color[j][i];
             newj = i;

             if( d[newi][newj] == 0 ){
                d[newi][newj] = d[i][j] + 1;
                myqueue.push( newi );
                myqueue.push( newj );
             }
         }


    }


    return 0;
}


int main(){

    int n,n1,n2,n3,ans,t;

    t = 0;


    while( cin >> n && n != 0 ){

        t++;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                cin >> color[i][j];

            }

        }

        cin >> n1 >> n2 >> n3;


        ans = bfs( n , n1 , n2 , n3 );

        cout << "Game #" << t << endl;

        if( ans == 0 )
            cout << "Destination is Not Reachable !" << endl << endl;
        else
            cout << "Minimum Number of Moves = " << ans << endl << endl;
    }



    return 0;
}
