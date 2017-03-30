#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t,n,m,nodenum[100],ans;
    vector<int> node[100];

    cin >> t;

    for( int i = 1 ; i <= t ; i++ ){

        cin >> n >> m;
        ans = 0;

        for( int j = 0 ; j < n ; j++ ){
            cin >> nodenum[j];
            while( !node[j].empty() )
                node[j].pop_back();
        }
        for( int j = 0 ; j < m ; j++ ){
            int a,b;
            cin >> a >> b;
            node[a].push_back(b);
        }
        int current = 0;
        while( node[current].size() > 0 ){
            int nodetemp,numtemp;
            numtemp = 0;
            for( unsigned int j = 0 ; j < node[current].size() ; j++ ){
                if( nodenum[ node[current][j] ] > numtemp ){
                    numtemp = nodenum[ node[current][j] ];
                    nodetemp = node[current][j];
                }
            }
            ans += numtemp;
            current = nodetemp;
        }
        cout << "Case " << i << ": " << ans << " " << current << endl;
    }
    return 0;
}
