#include<stdio.h>
#include<math.h>

int main (){

    unsigned long long int n,i,j,sum,ans;

    while (scanf("%lld",&n)==1){

        i=1;
        j=0;
        sum=0;
        ans=0;

        for(;sum<n;i++){
            sum=sum+i;
        }

        for(;j+1<i;j++){
            ans=ans+(pow(2,j))*(j+1);
        }

        ans=ans-(pow(2,j-1))*(sum-n);
        printf("%lld\n",ans);

    }

    return 0;

}
