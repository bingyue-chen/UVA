#include<iostream>
#include<deque>
#include<stdio.h>

using namespace std;
int m , field[105][105] , walk[4][2]={ { 1 , 0 } , { -1 , 0 } , { 0 , 1 } , { 0 , -1 } };

struct nodedata{
    int x;
    int y;
    int l;
};

typedef struct nodedata node;

int BFS( int x , int y ){

    bool visited[105][105] = { { false } };
    deque<node> colorstack;
    int newx,newy;

    node temp,newnode;
    temp.x = x;
    temp.y = y;
    temp.l = 0;
    colorstack.push_back( temp );

    while( !colorstack.empty() ){
        temp = colorstack.front();
        colorstack.pop_front();
        visited[temp.x][temp.y] = true;
        for( int i = 0 ; i < 4 ; i++ ){
            newx = temp.x + walk[i][0];
            newy = temp.y + walk[i][1];
            if( newx >= 0 && newy >=0 && newx < m && newy < m ){
                if( field[newx][newy] == 3 ){
                   return temp.l + 1;
                }
                else if( !visited[newx][newy] ){
                    newnode.x = newx;
                    newnode.y = newy;
                    newnode.l = temp.l + 1;
                    colorstack.push_back( newnode );
                }
            }
        }
    }
    return 0;
}

int main(){


    int i ,j;
    while( cin >> m ){
        for( i = 0 ; i < m ; i++ ){
            for( j = 0 ; j < m ; j ++ ){
                scanf( "%1d" , &field[i][j] );
            }
        }
        int maxl = 0,temp;
        for( int i = 0 ; i < m ; i++ ){
            for( int j = 0 ; j < m ; j ++ ){
                if( field[i][j] == 1 ){
                    temp = BFS( i , j );
                    if( maxl < temp ) maxl = temp;
                }
            }
        }
        cout << maxl << endl;
    }
    return 0;
}
