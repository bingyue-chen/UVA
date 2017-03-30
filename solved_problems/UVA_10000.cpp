#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n,s,t,a,b,ansx,ansl;
    vector<int> myvector[105];
    int place[105];
    queue<int> bfsqueue;

    t = 1;

    while( cin >> n && n != 0 ){


        for( int i = 1 ; i <= n ; i++ ){
            while( !myvector[i].empty() )
                myvector[i].pop_back();
            place[i] = 0;
        }

        cin >> s;
        ansx = s;
        ansl = 0;

        while( cin >> a >> b && !( a == 0 && b == 0 ) )
            myvector[a].push_back( b );

        bfsqueue.push( s );

        while( !bfsqueue.empty() ){

            int current = bfsqueue.front();
            bfsqueue.pop();

            for( vector<int>::iterator it = myvector[current].begin() ; it != myvector[current].end() ; ++it ){
                if( place[current] + 1 > place[*it] ){
                    place[*it] = place[current] + 1;
                    bfsqueue.push( *it );
                }
            }

        }

        for( int i = 1 ; i <= n ; i++ ){
            if( place[i] > ansl ){
                ansl = place[i];
                ansx = i;
            }
        }

        cout << "Case " << t++ << ": The longest path from " << s << " has length " << ansl << ", finishing at " << ansx << "." << endl << endl;
    }

    return 0;
}
