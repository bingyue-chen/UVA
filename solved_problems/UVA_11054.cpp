#include<stdio.h>

int main(){

    int n,i;
    long long int past,current,ans;
    while( scanf("%d",&n) && n ){
        ans = 0;
        scanf("%lld",&past);
        for( i = 1 ; i < n ; i++ ){
            scanf("%lld",&current);
            if( past > 0 )
                ans += past;
            else
                ans -= past;
            past = past + current;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
