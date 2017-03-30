#include<iostream>
#include<vector>
#include<stdio.h>

using   namespace std;

void DFS( int p , vector<char> node[] , bool visited[] ){

        visited[p] = true;

        for( unsigned int i = 0 ; i < node[p].size() ; i++ ){
            if( !visited[node[p][i]-'A'] ){
                DFS( node[p][i]-'A' , node , visited );
            }
        }
 }


int main(){

    int n;
    char c,x,y;
    bool flag = false;
    cin >> n;
    while( n-- ){

        vector<char> node[26];
        bool visited[26]={ false };
        int ans = 0,temp = 0;

        cin >> c;
        //cout << "*" << c << endl;
        if( n > 0 ){
            while( temp < 2 ){
                cin >> noskipws >> x;
                if( x == '\n' ) temp++;
                else{
                    cin >> y;
                    //cout << "*" << x << y << endl;
                    node[x-'A'].push_back(y);
                    node[y-'A'].push_back(x);
                    temp = 0;
                }
            }
        }
        else{
            cin >> x;
            while( cin >> x >> y ){
                //cout << "*" << x << y << endl;
                node[x-'A'].push_back(y);
                node[y-'A'].push_back(x);
                cin >> x;
            }
        }
        for( int i = 0 ; i <= c - 'A' ; i++ ){

            if( !visited[i] ){
                DFS( i , node , visited );
                ans++;
            }

        }
        if(flag)
            cout << endl;
        cout << ans << endl;
        flag = true;
    }
    return 0;
}
