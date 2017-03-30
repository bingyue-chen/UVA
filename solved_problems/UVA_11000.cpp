#include <iostream>

using namespace std;

unsigned int f;

unsigned int fc( unsigned int x ,unsigned int y, int n ){
    if( n == 0 ){
        f = y;
        return y;
    }
    else{
        return y + fc(y , x + y , n - 1 );
    }
}

int main (){
    int n;
    unsigned sum;
    while( cin >> n && n != -1 ){
        sum = fc( 1 , 1 , n - 1 );
        cout << sum - f + 1 << ' ' << sum + 1 << endl;
    }

    return 0;
}


