#include<iostream>
#include<vector>

using namespace std;

void DFS( int p , vector<int> node[] , bool visited[] ){

    visited[p] = true;
    for( unsigned int i = 0 ; i < node[p].size() ; i++ ){
        if( !visited[node[p][i]] )
            DFS( node[p][i] , node , visited );
    }
}

int main(){

    int t,n,m,l,x,y;

    cin >> t;

    while( t-- ){

        vector<int> node[10005];
        bool visited[10005]={false};
        int ans = 0;
        cin >> n >> m >> l;
        while(m--){
            cin >> x >> y;
            node[x].push_back(y);
            //node[y].push_back(x);
        }
        while(l--){
            cin >> x;
            if( !visited[x] )
                DFS( x , node , visited );
        }
        for( int i = 1 ; i <= n ; i++ )
                if( visited[i] ) ans++;
        cout << ans << endl;
    }
    return 0;
}
