#include <stdio.h>
#include <vector>
#include <queue>
#define MAXINT 2147483647

using namespace std;

struct compare{
    bool operator()( const pair<int,int>& a , const pair<int,int>& b ){
        return a.second > b.second;
    }
};

int dist[1005];
int cnt[1005];
int n;
vector< pair<int,int> > myvector[1005];

int count_number( int x );

int main(){

    int m,s,e,d,l;


    while( scanf("%d",&n) && n > 0 ){

        scanf("%d",&m);

        for( int i = 1 ; i <= n ; i++ ){
            dist[i] = MAXINT;
            cnt[i] = -1;
            myvector[i].clear();
        }

        while( m-- ){
            scanf("%d%d%d",&s,&e,&d);
            myvector[s].push_back( make_pair( e , d ) );
            myvector[e].push_back( make_pair( s , d ) );
        }

        priority_queue< pair<int,int> , vector< pair<int,int> > ,  compare > myqueue;
        dist[2] = 0;
        myqueue.push( make_pair( 2 , dist[2] ) );
        int vector_size;

        while( !myqueue.empty() ){

            s = myqueue.top().first;
            if( s == 1 )
                break;
            l = dist[s];
            myqueue.pop();
            vector_size = myvector[s].size();

            for( int i = 0 ; i < vector_size ; i++ ){

                e = myvector[s][i].first;
                d = myvector[s][i].second;

                if( l + d < dist[e] ){
                    dist[e] = l+d;
                    myqueue.push( make_pair( e , l + d ) );
                }

            }
        }

        printf("%d\n",count_number(1));

    }

    return 0;
}

int count_number( int x ){

    int c,e,vector_size;

    if( x == 2 )
      return 1;

    if( cnt[x] >= 0 )
      return cnt[x];

    vector_size = myvector[x].size();

    c = 0;

    for( int i = 0 ; i < vector_size ; i++ ){
        e = myvector[x][i].first;
        if( dist[e] < dist[x] )
            c += count_number( e );
    }
    cnt[x] = c;
    return cnt[x];

}
