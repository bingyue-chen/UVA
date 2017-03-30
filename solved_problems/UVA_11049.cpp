#include<iostream>
#include<deque>
#include<string>
using namespace std;

struct basic{
    string d;
    bool visited;
};
struct sstack{
    int x,y;
};

int main(){
    int sx,sy,ex,ey,wx1,wx2,wy1,wy2,counter;
    basic basicmap[6][6];
    sstack temp;
    int wall[3][2][2];
    int walk[4][2]={{ -1 , 0 },{ 1 , 0 },{ 0 , -1 },{ 0 , 1 }};
    bool flag;
    deque<sstack> basicmapstack;

    while( cin >> sx >> sy ){
        if( sx == 0 && sy ==0 ) break;
        cin >> ex >> ey;
        ex--;
        ey--;
        for( int i = 0 ; i < 3 ; i++ )
            for( int j = 0 ; j < 2 ; j ++ )
                cin >> wall[i][j][1] >> wall[i][j][0];
        for( int i = 0 ; i < 6 ; i++ )
            for( int j = 0 ; j < 6 ; j++ ){
                basicmap[i][j].d = "";
                basicmap[i][j].visited = false;
            }
        while( !basicmapstack.empty() )
            basicmapstack.pop_back();

        temp.x = sy - 1;
        temp.y = sx - 1;
        basicmap[sy - 1][sx - 1].visited = true;
        basicmapstack.push_back( temp );
        flag = false;
        while( !basicmapstack.empty() && !flag ){
            temp = basicmapstack.front();
            basicmapstack.pop_front();
            for( int i = 0 ; i < 4 && !flag ; i++ ){
                if( temp.x + walk[i][0] >= 0 &&
                    temp.x + walk[i][0] < 6 &&
                    temp.y + walk[i][1] >= 0 &&
                    temp.y + walk[i][1] < 6 &&
                    !basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].visited ){
                    if( i == 0 ){
                       wx1 = temp.x;
                       wy1 = temp.y;
                       wx2 = temp.x;
                       wy2 = temp.y + 1;
                    }
                    else if( i == 1 ){
                       wx1 = temp.x + 1;
                       wy1 = temp.y ;
                       wx2 = temp.x + 1;
                       wy2 = temp.y + 1;
                    }
                    else if( i == 2 ){
                       wx1 = temp.x;
                       wy1 = temp.y;
                       wx2 = temp.x + 1;
                       wy2 = temp.y;
                    }
                    else{
                       wx1 = temp.x;
                       wy1 = temp.y + 1;
                       wx2 = temp.x + 1;
                       wy2 = temp.y + 1;
                    }
                    counter = 0;
                    for( int j = 0 ; j < 3 ; j++ ){
                        if( wx1 >= wall[j][0][0] &&
                            wy1 >= wall[j][0][1] &&
                            wx2 <= wall[j][1][0] &&
                            wy2 <= wall[j][1][1]
                           )
                           counter++;
                    }
                    if( counter < 1 ){
                        basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].visited = true;
                        if( i == 1 ) basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].d = basicmap[temp.x][temp.y ].d + "S";
                        else if( i == 2 ) basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].d = basicmap[temp.x][temp.y ].d + "W";
                        else if( i == 3 ) basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].d = basicmap[temp.x][temp.y ].d + "E";
                        else basicmap[temp.x + walk[i][0]][temp.y + walk[i][1]].d = basicmap[temp.x][temp.y ].d + "N";
                        sstack newnode;
                        newnode.x = temp.x + walk[i][0];
                        newnode.y = temp.y + walk[i][1];
                        basicmapstack.push_back( newnode );
                        if( temp.x + walk[i][0] == ey && temp.y + walk[i][1] == ex ) flag = true;
                    }
                }
            }

        }
        cout << basicmap[ey][ex].d << endl;
    }

    return 0;
}
