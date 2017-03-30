#include<stdio.h>

int main(){

    int n , money , past , maxmoney;

    while( scanf( "%d", &n ) && n ){
        past = maxmoney = 0;
        while( n-- ){
            scanf( "%d", &money);
            past = money = ( past+money > money ) ? past+money : money;
            maxmoney = ( money > maxmoney )? money : maxmoney;
        }

        if( maxmoney )
            printf( "The maximum winning streak is %d.\n", maxmoney );
        else
            printf( "Losing streak.\n" );
    }
    return 0;
}
