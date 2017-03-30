#include <stdio.h>

int main()
{
int a,b,c,counter,d,n,i;
scanf("%d",&n);
for(i=counter=0;i<n;i++,counter=0)
{
scanf("%d %d %d",&a,&b,&c);
d=(a+b);
while(d>=c)
{
counter+=(d/c);
d=d/c+d%c;
}
printf("%d\n",counter);

}

return 0;
}
