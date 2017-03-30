#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100
using namespace std;

int main(){

    int t,i;
    string s;
    char c[52] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j'
                 ,'K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t'
                 ,'U','u','V','v','W','w','X','x','Y','y','Z','z'};
    int ans[MAX];
    string::iterator it;
    cin >> t;
    while( t-- ){

        cin >> s;
        for( i = 0 ; i < MAX ; i++ ){
            ans[i] = 0;
        }

        for( i = 0 , it = s.begin() ; it != s.end() ; ++it , ++i ){
            if( *it >= 'A' && *it <= 'Z' ) ans[i] = ( *it - 'A' ) * 2;
            else ans[i] = ( *it - 'a' ) * 2 + 1;
        }
        sort( ans , ans + i );
        do{
            for( int j = 0 ; j < i ; j++ ){
                cout << c[ans[j]];
            }
            cout << endl;
        } while ( std::next_permutation( ans , ans + i  ) );
    }

    return 0;
}
