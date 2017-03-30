#include <stdio.h>

int main(){

    int t,n,i;
    char ans[1000000],a,b;

    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&n);

        for( i = 0 ; i < n ; i++ ){

            scanf("\n%c %c",&a,&b);
            ans[i] = a + b - 2 * '0';

        }

        for( i = n - 1 ; i > 0 ; i-- ){

            ans[i-1] += ans[i]/10;
            ans[i] %= 10;

        }

        for( i = 0 ; i < n ; i++ ){
            printf("%d",ans[i]);
        }

        printf("\n");
        if( t )
            printf("\n");

    }

    return 0;
}
