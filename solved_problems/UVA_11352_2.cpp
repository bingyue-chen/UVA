#include <iostream>
#include <queue>

using namespace std;

struct node {
    char c;
    int l;
    bool visited;
};
struct bfsrecord{
    int x;
    int y;
};

int m,n;
node nodedata[105][105];
queue<bfsrecord> nodequeue;

void mark( int x , int y ){
    int mx[8]={-1,1,-2,2,-2,2,-1,1};
    int my[8]={-2,-2,-1,-1,1,1,2,2};

    for( int i = 0 ; i < 8 ; i++ ){
        for( int j = 0 ; j < 8 ; j ++ ){
            if( x + mx[i] >= 0 &&
                x + mx[i] < m &&
                y + my[j] >= 0 &&
                my[j] < n &&
                nodedata[ x + mx[i] ][ y + my[i] ].c == '.'
                ){
                    nodedata[ x + mx[i] ][ y + my[i] ].c = '*';
                }

        }
    }

}

int bfs( void ){

    int x,y,l;
    char c;
    l = 0;
    while( !nodequeue.empty() && l == 0 ){
        x = nodequeue.front().x;
        y = nodequeue.front().y;
        nodequeue.pop();
        for( int i = -1 ; i <= 1 ; i++ ){
            for( int j = -1 ; j <= 1 ; j++ ){
                if( x + i >= 0 && x + i < m && y + j >= 0 && y + j < n )
                    if( nodedata[x+i][y+j].c == '.' && nodedata[x+i][y+j].visited == false ){
                            nodedata[x+i][y+j].l = nodedata[x][y].l+1;
                            nodedata[x+i][y+j].visited = true;
                            struct bfsrecord re;
                            re.x = x + i;
                            re.y = y + j;
                            nodequeue.push( re );
                    }
                    else if( nodedata[x+i][y+j].c == 'B' ){
                        return nodedata[x][y].l+1;
                    }
            }
        }
    }

    return l;

}

int main(){

    int t,l;
    cin >> t;
    while( t-- ){
        cin >> m >> n;
        while( !nodequeue.empty() ) nodequeue.pop();
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                cin >> nodedata[i][j].c;
                nodedata[i][j].l = 0;
                nodedata[i][j].visited = false;
            }
        }

        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                if( nodedata[i][j].c == 'Z' ) mark( i , j );
                else if( nodedata[i][j].c == 'A' ){
                    bfsrecord re;
                    re.x = i;
                    re.y = j;
                    nodequeue.push( re );
                    nodedata[i][j].visited = true;
                }
            }
        }

        l = bfs();
        if( l > 0 )
            cout << "Minimal possible length of a trip is " << l << '\n';
        else
            cout << "King Peter, you can't go now!" << '\n';
        /*cout << '\n';
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < n ; j++ ){
                cout << nodedata[i][j].c;
            }
            cout << '\n';
        }*/

    }


    return 0;

}
