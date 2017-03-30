#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

void DFS( int p , vector<int> node[] , int dep[] , bool visited[] ){

    visited[p] = true;
    int n = (int)node[p].size();

    for( int i = 0 ; i < (int)node[p].size() ; i++){

        if( !visited[node[p][i]] ){

            DFS( node[p][i] , node , dep , visited );

        }

        n = max( n ,  dep[node[p][i]]+1 );
    }

    dep[p] = n;
}

int main(){

    int n,t,x;

    while( cin >> n && n ){

        vector<int> node[105];
        int dep[105]={}, maxd = 0 , ansi = 1;
        bool visited[105] = { false };

        for( int i = 1 ; i <= n ; i++ ){

            cin >> t;

            while( t-- ){

                cin >> x;
                node[i].push_back(x);

            }

        }

        for( int i = 1 ; i <= n ; i++ ){

            if( !visited[i] )
                DFS( i , node  , dep , visited );

        }

        for( int i = 1 ; i <= n ; i++ ){

            if( maxd < dep[i] ){

                maxd = dep[i];
                ansi = i;

            }

        }

        cout << ansi << endl;

    }

    return 0;

}
