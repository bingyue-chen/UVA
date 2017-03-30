#include <stdio.h>
#include <algorithm>
#include <string.h>

char word[1005];
int dp[1005][1005];

int f( int i , int j ){

    if( dp[i][j] == -1 ){
        if(i>j)dp[i][j]=0;
        else{

            if(word[i]==word[j])
                dp[i][j] = f(i+1,j-1);
            else
                dp[i][j] = std::min(f(i+1,j-1),std::min(f(i+1,j),f(i,j-1)))+1;
        }
    }

    return dp[i][j];
}

int main(){

    int T,t,i,j;

    scanf("%d\n",&T);

    for( t = 1 ; t <= T ; t++ ){

        memset( word , 0 , sizeof( word ) );
        memset( dp , -1 , sizeof( dp ) );

        fgets( word , sizeof( word ) , stdin );

        printf("Case %d: %d\n",t,f( 0 , strlen( word ) - 2 ) );
    }

    return 0;
}
