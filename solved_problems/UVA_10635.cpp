#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main(){

    int T,t,n,p,q,i,j,k;

    scanf("%d",&T);

    for( t = 1 ; t <= T ; t++){

        scanf("%d%d%d",&n,&p,&q);

        int prince[62500];

        vector<int> myvector;

        for( i = 1 ; i <= p+1 ; i++ ){
            scanf("%d",&j);
            prince[j] = i;
        }

        myvector.push_back(-1);

        for( i = 1 ; i <= q+1 ; i++ ){

            scanf("%d",&j);
            k = prince[j];

            if( k == 0 ) continue;

            if( k > myvector.back() )
                myvector.push_back( k );
            else
                *lower_bound( myvector.begin() , myvector.end() , k ) = k;
        }

        printf("Case %d: %d\n",t,myvector.size()-1);

    }

    return 0;
}
