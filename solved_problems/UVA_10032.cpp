#include <stdio.h>

int main(){

    int t,n,w[100],i,sum,hsum,hn,j;
    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&n);
        hn = n/2;

        for( i = 0 , sum = 0 ; i < n ; i++ ){
            scanf("%d",&w[i]);
            sum += w[i];
        }
        hsum = sum/2;
        long long dp[hsum+1],shift;
        shift = 1;
        for( i = 0 ; i <= hsum ; i++ )
            dp[i] = 0;
        dp[0] = 1;

        for( i = 0 ; i < n ; i++ )
            for( j = hsum ; j >= w[i] ; j-- )
                dp[j] |= dp[ j - w[i] ] << shift;

        if( n%2 )
            while( !( dp[hsum] & ( shift << hn ) ) && !( dp[hsum] & ( shift<< ( hn + 1 ) ) ) )
                hsum--;
        else
            while( !( dp[hsum] & ( shift << hn ) ) )
                hsum--;
        printf("%d %d\n",hsum,sum-hsum);
        if(t)
            printf("\n");
    }

    return 0;
}
