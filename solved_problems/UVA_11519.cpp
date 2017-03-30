#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
#define PI acos( -1.0 )
using namespace std;

int main(){
    double a[3] , b[3] , value;
    int t , x , flag , d;
    string command[1000] , val[1000];
    stringstream ss;
    cin >> t;
    while( t-- ){

        for( int i = 0 ; i < 3 ; i++ ){
            a[i] = b[i] = 0;
        }

        cin >> x;

        while( x-- ){

            cin >> command[0] >> val[0];

            if( val[0] == "?" ){
                if( command[0] == "fd") flag = 1;
                else if( command[0] == "bk" ) flag = 2;
                else if( command[0] == "lt" ) flag = 3;
                else if( command[0] == "rt" ) flag = 4;
                break;
            }
            else{
                ss << val[0];
                ss >> value;
                ss.clear();
                if( command[0] == "fd" ){
                    a[0] += value * cos( a[2] * PI / 180.0 );
                    a[1] += value * sin( a[2] * PI / 180.0 );
                }
                else if( command[0] == "bk" ){
                    a[0] -= value * cos( a[2] * PI / 180.0 );
                    a[1] -= value * sin( a[2] * PI / 180.0 );
                }
                else if( command[0] == "lt" ){
                    a[2] += value;
                }
                else if( command[0] == "rt" ){
                    a[2] -= value;
                }
                while( a[2] >= 360 ){
                    a[2] -= 360;
                }
            }
        }

        for( int i = 0 ; i < x ; i++ ){
            cin >> command[i] >> val[i];
        }
        d = 0;
        while( x ){
            x--;
            ss << val[x];
            ss >> value;
            ss.clear();
            if( command[x] == "fd" ){
                d -= value;
            }
            else if( command[x] == "bk" ){
                d += value;
            }
            else if( command[x] == "lt" ){
                b[2] -= value;
                while( b[2] <= -360 ){
                    b[2] += 360;
                }
                b[0] += d * cos( b[2] * PI / 180 );
                b[1] += d * sin( b[2] * PI / 180 );
                d = 0;
            }
            else if( command[x] == "rt" ){
                b[2] += value;
                while( b[2] >= 360 ){
                    b[2] -= 360;
                }
                b[0] += d * cos( b[2] * PI / 180 );
                b[1] += d * sin( b[2] * PI / 180 );
                d = 0;
            }
        }
        /*cout << a[0] << ',' << a[1] << ',' << a[2] << endl;
        cout << b[0] << ',' << b[1] << ',' << b[2] << endl;*/
        if( flag == 1 || flag == 2 ){
                if( a[0] != b[0] ){
                    value = ( ( a[0] - b[0] ) / cos( a[2] * PI / 180.0 ) );
                    cout << value << endl;
                }
                else if( a[1] != b[1] ){
                    value = ( ( a[1] - b[1] ) / sin( a[2] * PI / 180.0 ) );
                    cout << value << endl;
                }
                else cout << "0\n";

        }
        else if( flag == 3){
            if( d != 0){
                d = -d;
                value = 360 - acos( ( b[0] - a[0] ) / d ) / PI * 180.0 - a[2];
                while( value >= 360 ){
                    value -= 360;
                }
                while( value <= -360 ){
                    value += 360;
                }
                if( value >= 0 ) cout << value << endl;
                else cout << -value << endl;
            }
            else if( b[2] >= a[2] ) cout << ( b[2] - a[2] ) << endl;
            else cout << ( b[2] - a[2] + 360 ) << endl;
        }
        else if( flag == 4 ){
            if( d != 0 ){
                d = -d;
                value = 0 - acos( ( b[0] - a[0] ) / d ) / PI * 180.0 - a[2];
                while( value >= 360 ){
                    value -= 360;
                }
                while( value <= -360 ){
                    value += 360;
                }
                if( value > 0) cout << (int)value << endl;
                else cout << (int)-value << endl;
            }
            else if( a[2] >= b[2] ) cout << ( a[2] - b[2] ) << endl;
            else cout << ( a[2] - b[2] + 360 ) << endl;
        }
    }
    return 0;
}
