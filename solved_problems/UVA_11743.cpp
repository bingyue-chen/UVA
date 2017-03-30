#include <iostream>


using namespace std;

int main(){

    char c;
    int t,temp,sum1,sum2;

    cin >> t;
    while( t-- ){
        temp = sum1 = sum2 = 0;
        for(int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ;j < 4 ; j++ ){
                cin >> c;
                temp = c - '0';
                if( j%2 == 0 ){
                    temp *= 2;
                    while( temp > 0 ){
                        sum1 += temp % 10;
                        temp /= 10;
                    }
                }
                else{
                    sum2 += temp;
                }
            }
        }
        if( ( sum1 + sum2 )%10 == 0 ) cout << "Valid\n";
        else cout << "Invalid\n";

    }
    return 0;
}
