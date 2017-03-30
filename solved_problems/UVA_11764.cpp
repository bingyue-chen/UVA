#include <iostream>
using namespace std;

int main(){
    int t,n,x,y,l,h;

    cin >> t;

    for( int i = 1 ; i <= t ; i++ ){

        cin >> n;
        l = h = 0;

        cin >> x;
        n--;

        while( n-- ){
            cin >> y;

            if( x > y ) l++;
            else if( x < y ) h++;
            x = y;
        }


        cout << "Case " << i << ": " << h << ' ' << l << endl;

    }

    return 0;
}
