#include<iostream>
using namespace std;
long long n,a,b;

int next( long long cur ) {
	return (a*((cur*cur)%n)+b)%n;
}

int main(){

    int ans;
    long i ,j;
    while( cin >> n && n ){

        cin >> a >> b;

        i = j  = ans = 0;

        do{
            i = next( i );
            j = next( next( j ) );
        }while( i != j );

        do{
            j = next( j );
            ans++;
        }while( j != i );

        cout << ( n - ans ) << endl;

    }

    return 0;
}
