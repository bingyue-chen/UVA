#include <stdio.h>

int lis_and_lds( int *n , int l ){

    int i,j,dp[l],dp2[l],t,ans,t2;

    for( i = 0 ; i < l ; i++ )
        dp[i] = dp2[i] = 1;

    for( i = 0 ; i < l - 1 ; i++ ){
        t = dp[i] + 1;
        t2 = dp2[i] + 1;
        for( j = i+1 ; j < l ; j++ ){
            if( n[j] > n[i] && t > dp[j] ){
                dp[j] = t;
            }
            else if( n[j] < n[i] && t2 > dp2[j] ){
                dp2[j] = t2;
            }
        }
    }

    for( i = ans = 0 ; i < l ; i++ )
        if( dp2[i] + dp[i] - 1 > ans ) ans = dp2[i] + dp[i] - 1;

    return ans;
}

int main(){

    int t,aarray[2005],n,i;
    scanf("%d",&t);

    while( t-- ){
        scanf("%d",&n);
        for( i = n-1 ; i >= 0 ; i-- ){
            scanf("%d",&aarray[i]);
        }
        printf("%d\n", lis_and_lds(aarray,n) );
    }

    return 0;
}
