#include <stdio.h>
#include <string.h>

char martix[55][55] , str[55];
int l;
int dir[8][2] = { {-1,-1} , {-1,0} , {-1,1} , {0,1} , {0,-1} , {1,-1} , {1,0} , {1,1} };

int f( int x , int y , int d , int i ){

    if( i == l ) return 1;
    if( martix[x][y] != str[i] ) return 0;
    return f( x + dir[d][0] , y + dir[d][1] , d , i + 1 );

    /*while( i != l ){

        if(martix[x][y] != str[i] ) return 0;
        else{
            x += dir[d][0];
            y += dir[d][1];
            i++;
        }
    }

    return 1;*/
}

int main(){

    int t,m,n,i,j,k;
    char temp;

    int d = 'a' - 'A';

    scanf("%d",&t);

    while( t-- ){

        scanf("%d%d",&m,&n);
        memset( martix , 0 , sizeof( martix ) );

        for( i = 1 ; i <= m ; i++ ){
            scanf("%c",&temp);
            for( j = 1 ; j <= n ; j++ ){
                scanf("%c",&temp);
                martix[i][j] = ( temp <= 'Z' ) ? temp + d : temp ;
            }
        }

        scanf("%d",&k);
        scanf("%c",&temp);

        while( k-- ){

            l = 0;
            while( scanf("%c",&temp) && temp != '\n' ){
                str[l++] = ( temp <= 'Z' ) ? temp + d : temp ;
            }

            for( i = 1 ; i <= m ; i++ ){
                for( j = 1 ; j <= n ; j++ ){
                    if( martix[i][j] == str[0] ){
                        for( temp = 0 ; temp < 8 ; temp++ ){
                            if( f( i + dir[temp][0] , j + dir[temp][1] , temp , 1 ) == 1 ){
                                printf("%d %d\n",i,j);
                                i = j = temp = 55;
                            }
                        }
                    }
                }
            }

        }

        if( t )
            printf("\n");

    }

    return 0;
}
