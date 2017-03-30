#include <stdio.h>

int main(){

    long long int n,m,sum,ans,i;

    while( scanf("%lld%lld",&m,&n) != EOF ){

        for( ans = 1 ; n > 0 ; m-- , n-- ){
            ans *= m;
            while( ans%10 == 0 ) ans /= 10;
            ans %= 1000000000;
        }
        printf("%d\n",ans%10);
    }

    return 0;
}
