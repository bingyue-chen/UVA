#include <stdio.h>
#include <algorithm>

int main(){

    int n,r,i,j,k,s,d,l,t,ans;
    int dp[105][105];
    t = 0;
    while( scanf("%d%d",&n,&r) == 2 ){

        if( n == 0 && r == 0 ) break;

        for( i = 1 ; i <= n ; i++ ){
            for( j = 1 ; j <= n ; j++ )
                dp[i][j] = 0;
        }

        for( i = 0 ; i < r ; i++ ){
            scanf("%d%d%d",&s,&d,&l);
            dp[s][d] = dp[d][s] = l;
        }

        scanf("%d%d%d",&s,&d,&l);

        for( k = 1 ; k <= n ; k++ )
            for( i = 1 ; i <= n ; i++ )
                for( j = 1 ; j <= n ; j++ )
                    dp[i][j] = std::max(dp[i][j], std::min(dp[i][k], dp[k][j]) );

        ans = dp[s][d] - 1;
        ans = ( l/ans ) + ( l%ans > 0 );

        printf("Scenario #%d\n",++t);
        printf("Minimum Number of Trips = %d\n\n",ans);

    }

    return 0;
}
