#include <stdio.h>

int main(){

    long long int Pricemap[305][305],i,j,n,l,r;
    char c;

    for( j = 0 ; j < 305 ; j++ )
        Pricemap[0][j] = 1;

    for( i = 1 ; i < 305 ; i++ ){
        for( j = 1 ; j < 305 ; j++ )
            Pricemap[i][j] = Pricemap[i-j][j] + Pricemap[i][j-1];
    }

    while( scanf("%lld%c",&n,&c) != EOF ){

        if( c != '\n' ){
           scanf("%lld%c",&r,&c);
           if( c != '\n' ){
                scanf("%lld%c",&l,&c);
                if( r <= n )
                    printf("%lld\n",Pricemap[n][(l>n)*n+(l<=n)*l] - (r>0)*Pricemap[n][r-1]);
                else
                    printf("%d\n",0);
           }
           else
                printf("%lld\n",Pricemap[n][(r>n)*n+(r<=n)*r]);
        }
        else
            printf("%lld\n",Pricemap[n][n]);
    }
    return 0;
}
