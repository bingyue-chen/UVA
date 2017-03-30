#include <stdio.h>
#define MAX 1000
void countmines(char minesmap[MAX][MAX],int x,int y,int rx,int ry);
int main (){
    int x,y,i,j;
    long long t = 1;
    char minesmap[MAX][MAX]={0};
    char s;
    while(1){
        scanf("%d%d",&x,&y);
        if(x==0 && y==0)
            break;
        for( i =0 ; i <= x+1 ; i++ ){
            for( j =0 ; j <= y+1 ; j++ ){
                minesmap[i][j] = 0;
            }
        }
        scanf("%c",&s);
        for(i=1;i<=x;i++){
           for(j=1;j<=y;j++){
                scanf("%c",&s);
                if(s=='*')
                    minesmap[i][j]='*';
                else if(s=='.')
                    minesmap[i][j]='0';
           }
           scanf("%c",&s);
        }
        for(i=1;i<=x;i++){
            for(j=1;j<=y;j++){
                if(minesmap[i][j] == '*' ){
                    countmines(minesmap,i,j,x,y);
                }
            }
        }
         if( t>1 )printf("\n");
         printf("Field #%lld:\n",t);
         for(i=1;i<=x;i++){
           for(j=1;j<=y;j++){
               if(minesmap[i][j] == '*')
                printf("*");
               else
                printf("%c",minesmap[i][j]);
           }
           printf("\n");
        }
        t++;
    }

return 0;
}

void countmines(char minesmap[MAX][MAX],int x,int y,int rx,int ry){
    int i,j,d[3]={-1,0,1};
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(x+d[i]>=1 && x+d[i]<=rx && y+d[j]>=1 && y+d[j]<=ry && minesmap[x+d[i]][y+d[j]]!='*'){
                minesmap[x+d[i]][y+d[j]]++;
            }
        }
    }

}

