#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct nodedata{
    int times;
    char c;
};

bool com( struct nodedata a , struct nodedata b ){
    if( a.times != b.times ) return a.times > b.times;
    else return a.c < b.c;
}

int main(){

    int n;
    char encrypt;
    struct nodedata node[26];

    while( cin >> n ){
        for( int i = 0 ; i < 26 ; i++ ){
            node[i].c = (char)i + 'A';
            node[i].times = 0;
        }
        cin >> noskipws >> encrypt;
        while( n ){
            cin >> noskipws >> encrypt;
            if( encrypt == '\n' ) n--;
            else if( encrypt >= 'A' && encrypt <= 'Z' ){
                node[ encrypt - 'A' ].times++;
            }
            else if( encrypt >= 'a' && encrypt <= 'z' ){
                node[ encrypt - 'a' ].times++;
            }
        }
        sort( node , node + 26 , com );

        for( int i = 0 ; i < 26 && node[i].times != 0 ; i++ ){
            cout << node[i].c << " " << node[i].times << endl;
        }

    }

    return 0;
}
