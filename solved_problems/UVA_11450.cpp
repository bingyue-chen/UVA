#include <stdio.h>

int main(){

    int garments[25][25],t,i,j,k,m,c,n;


    scanf("%d",&t);

    while( t-- ){

        scanf("%d%d",&m,&c);
        int shopping[25][205]={0};

        for( i = 1 ; i <= c ; i++ ){
            scanf("%d",&garments[i][0]);
            for( j = 1 ; j <= garments[i][0] ; j++ ){
                scanf("%d",&garments[i][j]);
            }
        }

        shopping[0][0] = 1;

        for( i = 1 ; i <= c ; i++ )
            for( j = 1 ; j <= garments[i][0] ; j++ )
                for( k = garments[i][j] ; k <= m ; k++ )
                    shopping[i][k] += shopping[i - 1][k - garments[i][j]];

        for( i = m ; i >= 0 ; i-- ){
            if( shopping[c][i] ) break;
        }

        if( i > 0 ){
            printf("%d\n",i);
        }
        else{
            printf("no solution\n");
        }

    }

    return 0;
}
