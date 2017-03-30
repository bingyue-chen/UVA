#include <stdio.h>

int main(){

    int s,w,ss,ww,ans;

    ww = ss = ans = 0;
    while( scanf("%d%d" , &w , &s ) != EOF ){

        if( ww == 0 ){
            ww = w;
            ss = s - w;
            ans = 1;
        }
        else{

            if( ss >= w ){

                ww += w;
                if( ss - w < s - w ){
                    ss = ss - w;
                }
                else{
                    ss = s - w;
                }
                ans++;
            }
        }
        printf("ww = %d , ss = %d , ans = %d\n",ww,ss,ans);
    }
    printf("%d\n",ans);
    return 0;
}
