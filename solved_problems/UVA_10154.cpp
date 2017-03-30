#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct tutledata{
    int weight,strength;
};

bool compare( const tutledata& a , const tutledata& b ){
    return a.strength < b.strength;
}

int main(){

    int n , w , s , i;
    tutledata tutle[5610];
    n = 0;

    while( scanf( "%d %d" , &w , &s ) != EOF ){
        tutle[n].weight = w;
        tutle[n].strength = s;
        n++;
    }

    sort( tutle , tutle+n , compare );

    priority_queue<int> pq;

    for( i = 0  , w = 0 ; i < n ; i++ ){

        pq.push( tutle[i].weight );

        w += tutle[i].weight;
        if ( w > tutle[i].strength ) w -= pq.top(), pq.pop();

    }

    printf("%d\n" , pq.size() );

    return 0;
}
