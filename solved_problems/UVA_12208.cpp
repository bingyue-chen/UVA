#include <iostream>

using namespace std;

int f( int x ){
    int sum = 0;
    for( int i = 1073741824 ; i >= 1 && x > 0 ; i /= 2 ){
        if( x > i ) sum++;
        x %= i;
    }
    return sum;
}

int main(){

    int a,b,t = 1;
    long long int sum;
    while( 1 ){
        cin >> a >> b;
        if( a == 0 && b == 0 ) break;
        else{
            sum = 0;
            for( int i = a ; i <= b ; i++ ){
                sum += f( i );
            }
        }
        cout << "Case " << t++ << ": " << sum << '\n';
    }
    return 0;
}
