#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

    int t , x , dice[6];
    string a[6],b;
    char c;

    scanf("%d\n",&t);
    while( t-- ){
        for( int i = 0 ; i < 6 ; i++ ){
            scanf("%1d",&dice[i]);
            a[i] = dice[i] + '0';
        }
        scanf("%c",&c);
        cin >> b;
             if( b == ( a[0] + a[1] + a[2] + a[3] + a[4] + a[5] ) ) cout << "Equal\n";
        else if( b == ( a[0] + a[1] + a[3] + a[4] + a[5] + a[2] ) ) cout << "Equal\n";
        else if( b == ( a[0] + a[1] + a[4] + a[5] + a[2] + a[3] ) ) cout << "Equal\n";
        else if( b == ( a[0] + a[1] + a[5] + a[2] + a[3] + a[4] ) ) cout << "Equal\n";

        else if( b == ( a[1] + a[0] + a[2] + a[5] + a[4] + a[3] ) ) cout << "Equal\n";
        else if( b == ( a[1] + a[0] + a[5] + a[4] + a[3] + a[2] ) ) cout << "Equal\n";
        else if( b == ( a[1] + a[0] + a[4] + a[3] + a[2] + a[5] ) ) cout << "Equal\n";
        else if( b == ( a[1] + a[0] + a[3] + a[2] + a[5] + a[4] ) ) cout << "Equal\n";

        else if( b == ( a[2] + a[4] + a[0] + a[5] + a[1] + a[3] ) ) cout << "Equal\n";
        else if( b == ( a[2] + a[4] + a[5] + a[1] + a[3] + a[0] ) ) cout << "Equal\n";
        else if( b == ( a[2] + a[4] + a[1] + a[3] + a[0] + a[5] ) ) cout << "Equal\n";
        else if( b == ( a[2] + a[4] + a[3] + a[0] + a[5] + a[1] ) ) cout << "Equal\n";

        else if( b == ( a[4] + a[2] + a[0] + a[3] + a[1] + a[5] ) ) cout << "Equal\n";
        else if( b == ( a[4] + a[2] + a[3] + a[1] + a[5] + a[0] ) ) cout << "Equal\n";
        else if( b == ( a[4] + a[2] + a[1] + a[5] + a[0] + a[3] ) ) cout << "Equal\n";
        else if( b == ( a[4] + a[2] + a[5] + a[0] + a[3] + a[1] ) ) cout << "Equal\n";

        else if( b == ( a[3] + a[5] + a[2] + a[1] + a[4] + a[0] ) ) cout << "Equal\n";
        else if( b == ( a[3] + a[5] + a[1] + a[4] + a[0] + a[2] ) ) cout << "Equal\n";
        else if( b == ( a[3] + a[5] + a[4] + a[0] + a[2] + a[1] ) ) cout << "Equal\n";
        else if( b == ( a[3] + a[5] + a[0] + a[2] + a[1] + a[4] ) ) cout << "Equal\n";

        else if( b == ( a[5] + a[3] + a[2] + a[0] + a[4] + a[1] ) ) cout << "Equal\n";
        else if( b == ( a[5] + a[3] + a[0] + a[4] + a[1] + a[2] ) ) cout << "Equal\n";
        else if( b == ( a[5] + a[3] + a[4] + a[1] + a[2] + a[0] ) ) cout << "Equal\n";
        else if( b == ( a[5] + a[3] + a[1] + a[2] + a[0] + a[4] ) ) cout << "Equal\n";

        else cout << "Not Equal\n";
    }

    return 0;

}
