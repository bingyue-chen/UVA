#include <stdio.h>
#include <algorithm>
#include <functional>

int sticks[25],n,sum,used[25];

int dfs( int l , int tsum , int edge ){

    int i;

    if( edge == 3 ) return 1;

    for( i = l ; i < n ; i++ ){
        if( used[i] == 0 ){
            if( tsum + sticks[i] == sum ){
                used[i] = 1;
                if( dfs( 0 , 0 , edge + 1 ) ) return 1;
                used[i] = 0;
            }
            else if(  tsum + sticks[i] < sum ){
                used[i] = 1;
                if( dfs( i + 1 , tsum+sticks[i] , edge ) ) return 1;
                used[i] = 0;
            }
        }
    }

    return 0;
}

int main(){

    int t,i,max_length;

    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&n);

        for( i = sum = max_length = 0 ; i < n ; i++ ){
            scanf("%d",&sticks[i]);
            if( sticks[i] > max_length ) max_length = sticks[i];
            sum += sticks[i];
            used[i] = 0;
        }

        if( sum%4 == 0 && max_length <= sum/4 ){
            std::sort( sticks , sticks + n , std::greater<int>() );
            sum /= 4;
            if( dfs( 0 , 0 , 0 ) ) printf("yes\n");
            else printf("no\n");
        }
        else
            printf("no\n");
    }

    return 0;
}
