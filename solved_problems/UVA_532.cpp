#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

struct nodedata{
    int x,y,z,d;
};
typedef struct nodedata node;
int x,y,z;
char maze[35][35][35];
int walk[6][3]={ {1,0,0} , {-1,0,0} , {0,1,0} , {0,-1,0} , {0,0,1} , {0,0,-1} };
int BFS(int,int,int);

int main(){
    memset(maze,'#',sizeof(maze));
    int sx,sy,sz,ans,i,j,k;
    char c;
    while( scanf("%d%d%d",&z,&x,&y) ){
        if( x == 0 && y == 0 && z == 0 )
            break;
        else{

            sx = sy = sz = ans = 0;
            scanf("%c",&c);
            for( i = 1 ; i <= z ; ++i ){
                for( j = 1 ; j <= x ; ++j ){
                    for( k = 1 ; k <= y ; ++k ){
                        scanf("%c",&maze[i][j][k] );
                        if( maze[i][j][k] == 'S' ){
                            sz = i; sx = j; sy =k;
                        }
                    }
                    scanf("%c",&c);
                }
                scanf("%c",&c);
            }
            ans = BFS( sz , sx ,sy );
            if( ans )
                printf("Escaped in %d minute(s).\n",ans);
            else
                printf("Trapped!\n");
        }
    }
    return 0;
}

int BFS( int sz , int sx , int sy ){

    int i;
    queue<node> bfsqueue;
    node current,next;
    current.x = sx;
    current.y = sy;
    current.z = sz;
    current.d = 0;

    bfsqueue.push(current);
    maze[current.z][current.x][current.y] = 'X';

    while( !bfsqueue.empty() ){

        current = bfsqueue.front();
        bfsqueue.pop();


        for( i = 0 ; i < 6 ; ++i ){

            next.z = current.z + walk[i][0];
            next.x = current.x + walk[i][1];
            next.y = current.y + walk[i][2];
            next.d = current.d + 1;

            if( maze[next.z][next.x][next.y] == '.' ){
                bfsqueue.push( next );
                maze[next.z][next.x][next.y] = 'X';
            }
            else if( maze[next.z][next.x][next.y] == 'E' )
                return next.d;

        }

    }
    return 0;
}
