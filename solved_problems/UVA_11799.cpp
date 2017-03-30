#include <iostream>
using namespace std;

int main(){
    int t,MAX,n,N;
    cin >> t;
    for( int i = 1 ; i <= t ; i++ ){
        MAX = n = N = 0;
        cin >> N;

        while( N-- ){
            cin >> n;
            if ( n > MAX) MAX = n;
        }
        cout << "Case " << i << ": " << MAX << endl;

    }
    return 0;
}
