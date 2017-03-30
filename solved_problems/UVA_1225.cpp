#include <iostream>

using namespace std;

int main(){

    int t,ans[10],n;

    cin >> t;

    while( t-- ){

        cin >> n;

        for( int i = 0 ; i < 10 ; i++ )
            ans[i] = 0;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = i ; j > 0 ; j /= 10 )
                ans[ ( j % 10 ) ]++;
        }

        for( int i = 0 ; i < 9 ; i++ )
            cout << ans[i] << ' ';
        cout << ans[9] << endl;

    }


    return 0;
}
