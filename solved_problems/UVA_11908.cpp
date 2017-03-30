#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct ad{
    int s , e , m;
};

bool compare( const ad a , const ad b ){
    return a.e < b.e;
}

int main (){

    int t , n , floor[200010] ,s ,  e , m;
    struct ad vad[30005];

    cin >> t;

    for( int i = 1 ; i <= t ; ++i ){

        memset( floor , 0 , 200010 );

        cin >> n;

        for( int j = 0 ; j < n ; j++ ){
            cin >> s >> e >> m;
            vad[j].s = s;
            vad[j].e = s + e -1;
            vad[j].m = m;
        }

        sort( vad , vad + n , compare );

        int j,maxfloor = 0;
        for( int itad = 0 ; itad < n ; ++itad ){
            if( maxfloor < vad[itad].s ){
                floor[vad[itad].e] = floor[maxfloor]+vad[itad].m;
            }
            else{
                for( j = vad[itad].s - 1 ; j > 0 && floor[j] == 0 ; --j );
                floor[vad[itad].e] = max( floor[maxfloor] , ( floor[j] + vad[itad].m ) );
            }
            maxfloor = vad[itad].e;
        }

        cout << "Case " << i << ": " << floor[maxfloor] << endl;
    }


    return 0;
}
