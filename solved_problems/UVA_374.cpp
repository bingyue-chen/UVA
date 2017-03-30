#include<stdio.h>

int bigmod( int , int , int );

int main(){

    int b,p,m;

    while( scanf("%d%d%d",&b,&p,&m) != EOF ){

        printf("%d\n",bigmod(b,p,m));

    }

    return 0;
}

int bigmod( int b , int p , int m ){

    int x;

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
