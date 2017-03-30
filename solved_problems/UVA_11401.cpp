#include <stdio.h>

int main(){

    static unsigned long long int ans[1000005],i;

    for( i = 4 , ans[3] = 0 ; i < 1000005 ; i++ ){
        ans[i] = ans[i-1] + ( ( i - 1 )*( i - 2 ) / 2 - ( i - 1 ) / 2 ) / 2;
    }

    while( scanf("%lld",&i) && i >= 3  ){
        printf("%lld\n",ans[i]);
    }

    return 0;
}
