#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int t,p;
long long int mini,maxi,q,g;
string s;

void start(){
    int i;
    s = "";
    for( i = 0 ; i < p - 1 ; i ++ )
        s += '1';
    s += '2';
}

int next( int x ){
    stringstream ss;
    long long int n;

    ss << s;
    ss >> n;
    if( maxi == 0 && ( n % g ) == 0 ){
        maxi = mini = n;
    }
    else if( n < mini && ( n % g ) == 0 ){
        mini = n;
    }
    else if( n > maxi && ( n % g ) == 0 ){
        maxi = n;
    }

    for( int i = x ; i < p - 1 ; i++ ){
        s.replace( i , 1 , "2" );
        next( i + 1 );
        s.replace( i , 1 , "1" );
    }
}

int main (){
    //cin >> t;
    t = 1;
    for( int i = 1 ; i <= t ; i++ ){
        //cin >> p >> q;
        p = 17; q = 3;
        g = ( int )pow( 2.0 , ( float )q );
        mini = maxi = 0;
        start();
        if( p > q ){
            next( p - q - 1 );
            if( maxi > 0 ){
                stringstream ss;
                ss << maxi;
                s = "";
                ss >> s;
                s.replace( 0 , p - q - 1 , p - q - 1 , '2' );
                ss.clear();
                ss << s;
                ss >> maxi;
            }
        }
        else{
            next( 0 );
        }
        cout << "Case " << i << ": ";
        if( maxi == 0 )
            cout << "impossible\n";
        else if( mini == maxi )
            cout << maxi << endl;
        else
            cout << mini << " " << maxi << endl;
    }
    return 0;
}
