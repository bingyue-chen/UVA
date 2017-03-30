#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main(){

    int t,n,s,l,m;
    map<int,int> ad;
    map<int,int>::iterator it,f;

    cin >> t;

    for( int i = 1 ; i <= t ; i++ ){

        ad.clear();

        cin >> n;

        while( n-- ){

            cin >> s >> l >> m;

            if( s + l <= 100000 ){

                if( ad.empty() ){
                    ad.insert( pair<int,int>( s + l , m ) );
                }
                else{
                    f = ad.find( s + l );
                    for( it = ad.begin() ; it != ad.end() ; it++ ){
                        if( s > it->first ) break;
                    }

                    if( it == ad.end() && f == ad.end() ){
                        ad.insert( pair<int,int>( s + l , m ) );
                    }
                    else if( it != ad.end() && f == ad.end() ){
                        ad.insert( pair<int,int>( s + l , it->second + m ) );
                        ad.erase( it );
                    }
                    else if( it == ad.end() && f != ad.end()){
                        f->second = max( f->second , m );
                    }
                    else{
                        f->second = max( f->second , m + it->second );
                        ad.erase( it );
                    }
                }

            }

        }
        for( it = ad.begin() , m = 0; it != ad.end() ; it++ ){
            if( it->second > m ) m = it->second;
        }
        cout << "Case " << i << ": " << m << endl;

    }

    return 0;
}
