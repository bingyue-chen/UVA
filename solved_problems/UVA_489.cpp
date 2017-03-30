#include <stdio.h>
#define MAX 30

using namespace std;

int main (){

    bool ans[MAX] = {} , input[MAX] = {};
    int t , x , flag1 , flag2 , n ;
    char c;

    while( scanf("%d",&t) && t!= -1 ){

        printf("Round %d\n",t);

        for( int i = 0 ; i < MAX ; i++ ){
            ans[i] = input[i] = 0;
        }

        scanf("%c",&c);
        n = 0;
        while( scanf("%c",&c) && c != '\n' ){
            x = c - 'a';
            if( ans[x] == 0 ){
                ans[x] = 1;
                n++;
            }
        }

        flag1 = flag2 = 0;
        while( scanf("%c",&c) && c != '\n' ){
            x = c - 'a';
            if( flag1 <= 6 && flag2 < n )
                if( input[x] == 0 ){
                    input[x] = 1;
                    if( ans[x] == 1 ) flag2++;
                    else flag1++;
                }
        }
        if( flag1 > 6 ) printf("You lose.\n");
        else if( flag2 == n ) printf("You win.\n");
        else printf("You chickened out.\n");
    }

    return 0;
}
