#include <iostream>

using namespace std;

int main(){

    int n,k,j,g,t;

    cin >> t;
    for( int i = 1 ; i <= t ; i++ ){
        cin >> n >> k;

        for( g = 0 , j = 1 ; j <= n ; j++ ) {
            g = ( g + k ) % j;
        }
        cout << "Case " << i << ": " << g + 1 << endl;
    }
    return 0 ;
}
