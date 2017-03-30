#include <stdio.h>
long long int f(int x);
long long int g(int x,int y);

int main (){
    long long int a,b;

    while(1){
        scanf("%lld%lld",&a,&b);
        if(a == 0 && b == 0)
            break;
        printf("%lld\n",g(a,b)/f(b));
    }
return 0;
}

long long int f(int x){
    if(x>0)
        return x*f(x-1);
    else
        return 1;
}

long long int g(int x,int y){
    if(x>y)
        return x*g(x-1,y);
    else
        return 1;
}
