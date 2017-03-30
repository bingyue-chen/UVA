#include<stdio.h>
#include<string.h>

int main() {

    int t , n , p , r;
    long long myqueue[15][15][15];

    myqueue[1][1][1] = 1;

    for( n = 2 ; n <= 13 ; n++ )
        for( p = 1; p <= n ; p++ )
            for( r = 1 ; r <= n ; r++ )
                myqueue[n][p][r] = myqueue[n-1][p][r]*(n-2) + myqueue[n-1][p-1][r] + myqueue[n-1][p][r-1];

    scanf("%d", &t );

    while( t-- ) {
        scanf("%d %d %d", &n , &p , &r);
        printf("%lld\n", myqueue[n][p][r]);
    }

    return 0;
}
