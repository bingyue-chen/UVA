#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int,int> pa;

bool comp( const pa& a, const pa& b){
    if( a.second == b.second )
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main(){

    int t,c[26]={};
    string s;
    vector<pa> vec;
    cin >> t;
    t++;

    while( t-- ){
        getline( cin , s );
        for( string::iterator it = s.begin() ; it != s.end() ; it++ ){
            if( *it >= 'A' && *it <= 'Z' )  c[*it-'A']++;
            else if( *it >= 'a' && *it <= 'z' ) c[*it-'a']++;
        }
    }
    for( int i = 0 ; i < 26 ; i++ ){
        if( c[i] > 0 ) {
            vec.push_back( make_pair( i , c[i] ) );
        }
    }

    sort( vec.begin() , vec.end() , comp );

    for( vector<pa>::iterator it = vec.begin() ; it != vec.end() ; it++ ){
        s = 'A' + (*it).first;
        cout << s << ' ' << (*it).second << endl;
    }


    return 0;
}
