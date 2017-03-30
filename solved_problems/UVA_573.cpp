#include <iostream>
using namespace std;
int main(){

    double h,u,d,f;

    while ( cin >> h >> u >> d >> f ){

        if( h == 0 ) break;

        double height = 0,down = u*f/100.0;
        int day = 0;
        while(1){

            day++;

            if( u > 0 )
                height += u;
            if( height > h){
                cout << "success on day " << day << endl;
                break;
            }

            height -= d;
            if( height < 0 ){
                cout << "failure on day " << day << endl;
                break;
            }
            u -= down;
        }
    }

    return 0;
}
