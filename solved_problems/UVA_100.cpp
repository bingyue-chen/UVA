#include <stdio.h>
int cycle_length(int x);
int time;

int main (){
    int a,b,temp,max_cycle_length,i;
    while(scanf("%d%d",&a,&b)!=EOF){
    printf("%d %d",a,b);
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    for(i=a,time=max_cycle_length=0;i<=b;i++,time=0){
        cycle_length(i);
        if(time>max_cycle_length){
            max_cycle_length=time;
        }
    }
    printf(" %d\n",max_cycle_length);
    }
    return 0;
}
int cycle_length(int x){
    time++;
    if(x==1){
        return 0;
    }
    else if(x%2==0){
        return cycle_length(x/2);
    }
    else{
        return cycle_length(3*x+1);
    }
}

