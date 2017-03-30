#include <stdio.h>

static inline void switch_pointer( int** c1 , int** c2 ){
    int *t;
    t = *c1;
    *c1 = *c2;
    *c2 = t;
}

int main(){

    int n,m,line1[105],line2[105],line3[105],*p1,*p2,i,j,k,ans;

    while( scanf("%d%d",&n,&m) == 2 && n != 0 && m != 0 ){

        for( i = 1 ,  p1 = line1 , p2 = line2 , ans = 0 ; i <= n ; i++ , switch_pointer( &p1 , &p2 ) ){
            for( j = 1 ; j <= m ; j++ ){
                scanf("%1d",&p1[j]);
                if( i == 1 ) p2[j] = 0;
                if( p1[j] == 1 ) p1[j] += p2[j];
                line3[j] = 0;
                for( k = j-1 ; k >= 1 && p1[k] > p1[j] ; k-- );
                line3[j] = ( j - k )*p1[j] + line3[k];
                ans += line3[j];
            }
        }

        printf("%d\n",ans);

    }

    return 0;

}
