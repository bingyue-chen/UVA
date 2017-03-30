#include <iostream>
#include <iomanip>
using namespace std;

int t[100] , light[100][2];

void setstart(){
    for( int i = 0 ; i < 100 ; i++ ){
        t[i] = light[i][1] = light[i][0] = 0;
    }
}
void change( int n ){
    int mini = light[0][1] , mark = 0;
    for( int i = 1 ; i < n ; i++ ){
        if( light[i][1] < mini ) {
            mark = i;
            mini = light[i][1];
        }
    }
    light[mark][0] = light[mark][1] + 1 ;
    light[mark][1] += t[mark];
    light[mark][0] = light[mark][1] + 1;
    light[mark][1] += t[mark];
}
int check( int n ){
    int mini = light[0][1] , m = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( light[i][1] < mini ) {
            mini = light[i][1];
        }
        if( light[i][0] > m ){
            m = light[i][0];
        }
    }
    //cout << m << ',' << mini << '\n';
    if( ( mini - 5 ) >= m ){
        if( m > 18001 )
            return -1;
        else
            return m;
    }
    else if( m > 18001 ) return -1;
    else
        return 0;
}
int main(){

    int flag = 0,x,i,h,m,s;

    while( 1 ){
        setstart();
        i = 0;
        while( i >= 0 ){
            cin >> x;
            if( x == 0 ) break;
            else {
                t[i] = x;
                light[i][0] = 0;
                light[i][1] = x;
                i++;
            }
        }

        if( i == 0 ) flag++;
        else flag = 0;

        if( flag == 3 ) break;
        if( i > 0 ){
        do{
            //cout << "enter loop\n" ;
            change( i );
            x = check( i );
            //cout << x << '\n' ;
        }while( x == 0 );

        if( x == -1 )cout << "Signals fail to synchronise in 5 hours\n";
        else {
            x--;

            h = x / 3600;
            x %= 3600;
            m = x / 60;
            x %= 60;
            s = x;
            cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s << endl;
        }
        }
    }
    return 0;
}
