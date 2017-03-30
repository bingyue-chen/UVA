#include <stdio.h>

int main(){

    int t,k,flag,i,sum;

    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&k);

        k = ( k < 0 ) ? -k : k;

        i = sum = 1 , flag = k%2;

        while( sum < k || sum%2 != flag ) i++ , sum += i;

        printf("%d\n",i);

        if( t )
            printf("\n");

    }

    return 0;

}
