#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int classes[10003][5];

int compare( int n ){

    int sum = 0;

    for( int i = 0 ; i < n ; i++ , sum = 0 ){
        for( int j = 0 ; j < 5 ; j++ ){
            if( classes[i][j] == classes[n][j] ) sum++;
            else break;
        }
        if( sum == 5 ) return i;
    }

    return -1;

}

int main(){

    int n , x[10003] ,s;

    while( cin >> n && n > 0 ){

        for( int i = 0 ; i < 10003 ; i ++ ){
            x[i] = 1;
        }
        s = 0;
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < 5 ; j++ ){
                cin >> classes[i][j];
            }
            sort( classes[i] , classes[i] +  5 , greater<int>() );

            s = compare( i );
            if( s >= 0 ) x[s]++;
        }

        sort( x , x +  n , greater<int>() );
        s = 0;
        for( int i = 0 ; x[i] == x[0]  && i < n ; i++ , s += x[0] );
        cout << s << endl;

    }

    return 0;
}
