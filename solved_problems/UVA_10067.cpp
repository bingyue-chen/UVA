#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct nodedata{
    int n[4],d;
};

typedef nodedata node;

int BFS( node , node , bool[] );


int main(){

    int t,n;
    cin >> t;

    while( t-- ){

        node s,e;
        bool visited[10000] = { false };
        int a,b,c,d;

        cin >> s.n[0] >> s.n[1] >> s.n[2] >> s.n[3];
        cin >> e.n[0] >> e.n[1] >> e.n[2] >> e.n[3];
        cin >> n;

        while( n-- ){
            cin >> a >> b >> c >> d;
            visited[a*1000+b*100+c*10+d] = true;
        }

        cout << BFS( s , e , visited ) << endl;
    }

    return 0;

}

int BFS( node s , node e , bool visited[] ){

    queue<node> bfsqueue;
    node current,next;
    s.d = 0;

    if( s.n[0] == e.n[0] && s.n[1] == e.n[1] && s.n[2] == e.n[2] && s.n[3] == e.n[3] )
        return s.d;

    bfsqueue.push( s );
    visited[ (s.n[0])*1000 + (s.n[1])*100 + (s.n[2])*10 + (s.n[3]) ] = true;

    while( !bfsqueue.empty() ){

        current = bfsqueue.front();
        bfsqueue.pop();

        for( int i = 0 ; i < 4 ; i ++ ){

            next = current;
            next.n[i] = ( current.n[i] + 1 ) % 10;
            next.d = next.d+1;

            if( next.n[0] == e.n[0] && next.n[1] == e.n[1] && next.n[2] == e.n[2] && next.n[3] == e.n[3] )
                return next.d;

            if( visited[ (next.n[0])*1000 + (next.n[1])*100 + (next.n[2])*10 + (next.n[3]) ] != true ){
                bfsqueue.push( next );
                visited[ (next.n[0])*1000 + (next.n[1])*100 + (next.n[2])*10 + (next.n[3]) ] = true;
            }

        }
        for( int i = 0 ; i < 4 ; i ++ ){

            next = current;
            next.n[i] = current.n[i] - 1;
            if( next.n[i] < 0 ) next.n[i] = 9;
            next.d = next.d+1;

            if( next.n[0] == e.n[0] && next.n[1] == e.n[1] && next.n[2] == e.n[2] && next.n[3] == e.n[3] )
                return next.d;

            if( visited[ (next.n[0])*1000 + (next.n[1])*100 + (next.n[2])*10 + (next.n[3]) ] != true ){
                bfsqueue.push( next );
                visited[ (next.n[0])*1000 + (next.n[1])*100 + (next.n[2])*10 + (next.n[3]) ] = true;
            }

        }

    }

    return -1;
}
