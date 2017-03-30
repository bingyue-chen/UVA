#include <iostream>

using namespace std;

int main(){

    int n,current,past,i,result[3000];
    while( cin >> n ){
        for( i = 0 ; i < n ; i++ )
            result[i] = 0;
        cin >> past;
        for( i = 1 ; i < n ; i ++ ){
            cin >> current;
            if( past > current )
                result[past-current]++;
            else
                result[current-past]++;
            past = current;
        }
        for( i = 1 ; i < n ; i++ ){
            if( result[i]!=1 ) break;
        }
        if( i == n ) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0;
}
