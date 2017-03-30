#include <iostream>
#define MAX 3000
using namespace std;

int n,num[MAX],pointer;

void product( int number ){
    for( int i = MAX-1 ; i >= pointer ; i-- )
        num[i] = num[i]*number;
}


void carry( void ){
    for( int i = MAX-1 ; i > pointer ; i-- ){
        num[i-1] += num[i] / 10;
        num[i] = num[i] % 10;
    }
    while( num[pointer]/10 > 0 ){
        num[pointer-1] = num[pointer] / 10;
        num[pointer] = num[pointer] % 10;
        pointer --;
    }
}

int main(){
    while( cin >> n ){
        cout << n << "!" << endl;
        if( n == 0 )
            cout << "1";
        else{
            for( int i = 0 ; i < MAX-1 ; i++ )
                num[i] = 0;
            num[MAX-1] = 1;
            pointer = MAX-1;

            for( int i = 1 ; i <= n ; i++ ){
                product( i );
                carry();
            }
            for( int i = pointer ; i < MAX ; i++ )
                cout << num[i];
        }
        cout << endl;
        //cout << pointer << endl;
    }

    return 0;

}

