#include <stdio.h>

int bigmod( int b , int p , int m ){

    long long int x;

    if( p == 0 ){
        return 1;
    }
    else if( p%2 == 0 ){
        x = bigmod( b , p/2 , m );
        return (x*x)%m;
    }
    else{
        x = bigmod( b , (p-1)/2 , m );
        return ((b%m)*((x*x)%m))%m;
    }

}

int main(){

    int n;

    while( scanf("%d",&n) && n != -1 ){

        /*if( n%2 == 0 ){
            printf("%d is not a Jimmy-number\n",n);
            continue;
        }*/
        if( bigmod( 2 , n-1 , n ) == 1 ){
            printf("%d is a Jimmy-number\n",n);
        }
        else{
            printf("%d is not a Jimmy-number\n",n);
        }

        printf("%d\n",bigmod( 2 , n-1 , n ));

    }

    return 0;
}

