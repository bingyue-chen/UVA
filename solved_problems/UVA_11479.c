#include <stdio.h>

int main (){
    long long int t,a,b,c,temp,i;
    scanf("%lld",&t);
    for(i=1;i<=t && t<20;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>b){
            temp=b;
            b=a;
            a=temp;
        }
        if(b>c){
            temp=c;
            c=b;
            b=temp;
        }
        if(a>b){
            temp=b;
            b=a;
            a=temp;
        }
        if( (a+b) >c && a>0 && b>0 && c>0 && b>(c-a) && a>(c-b)){
            if(a == b && b == c)
                printf("Case %lld: Equilateral\n",i);
            else if( a == b  ||  b == c )
                printf("Case %lld: Isosceles\n",i);
            else
                printf("Case %lld: Scalene\n",i);
        }
        else{
            printf("Case %lld: Invalid\n",i);
        }
    }
    return 0;
}
