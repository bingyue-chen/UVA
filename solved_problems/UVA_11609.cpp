#include<stdio.h>
//11609
long long int bigmod( long long int b , long long int p , long long int m ){

    long long int x;

    if( p == 0 ){
        return 1;
    }
    else if( p%2 == 0 ){
        x = bigmod( b , p/2 , m );
        return ( x * x ) % m;
    }
    else{
        x = bigmod( b , ( p - 1 ) / 2 , m );
        return ( ( b % m ) * ( ( x * x ) % m ) ) % m;
    }

}

int main(){

    long long int t , i , n;

    scanf( "%lld" , &t );

    for( i = 1 ; i <= t ; i++ ){

        scanf( "%lld" , &n );
        printf( "Case #%lld: %lld\n" , i , ( n * bigmod( 2 , n-1 , 1000000007 )  )% 1000000007 );

    }

    return 0;

}
