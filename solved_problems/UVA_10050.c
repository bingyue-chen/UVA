#include <stdio.h>
#define N 4000
#include <string.h>
int main()
{
    int s[N]={0};
    int n=0,day=0,i=0,f=0,part=0,minus=0,j=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&day);
        scanf("%d",&part);
        for(i=0;i<part;i++){
            scanf("%d",&f);
            for(j=1;(f*j)<=day;j++){
                s[f*j]=1;
            }
        }
        for(i=1;i<=day;i++){
            if(s[i]==1 && i%7!=0 && i%7!=6)
                minus++;
        }
        memset(s,0,N);
        printf("%d\n",minus);
        minus=0;

    }
return 0;
}
