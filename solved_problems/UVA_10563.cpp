#include <stdio.h>

struct node{
    char c;
    bool visited;
};

node mymap[105][85];

bool check( int x , int y , int l , char c ){

    int i,counter;

    counter = 0;

    for( i = 0 ; i <= l ; i++ ){
        if( mymap[x+l][y+i].c != 'A' && mymap[x+l][y+i].c != c )
            return false;
        counter += mymap[x+l][y+i].c;
    }

    for( i = 0 ; i < l ; i++ ){
        if( mymap[x+i][y+l].c != 'A' && mymap[x+i][y+l].c != c )
            return false;
        counter += mymap[x+i][y+l].c;
    }

    return counter >= (2*l+1)*c;

}

void mark( int x , int y , int l , char c ){

    int i;

    for( i = 0 ; i <= l ; i++ ){
        mymap[x+l][y+i].c = c;
        mymap[x+l][y+i].visited = true;
    }


    for( i = 0 ; i < l ; i++ ){
        mymap[x+i][y+l].c = c;
        mymap[x+i][y+l].visited = true;
    }
}

char f( int x , int y , int m , int n ){

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    int i;
    bool flag[5]={ false };

    for( i = 0 ; i < 4 ; i++ ){
        if( x+dx[i] >=0 && x+dx[i] < m && y+dy[i] >=0 && y+dy[i] < n && mymap[x+dx[i]][y+dy[i]].visited ){
            flag[ mymap[x+dx[i]][y+dy[i]].c -'A' ] = true;
        }
    }
    for( i = 0 ; i < 5 ; i++ ){
        if( !flag[i] )
            return i+'A';
    }
    return 'A';
}

void f2( int x, int y , int l , int m , int n ){

    int i;

    for( i = 0 ; i <= l ; i++ ){
        if( !mymap[x+l][y+i].visited )
            mymap[x+l][y+i].c = f( x+l , y+i , m ,n );
    }


    for( i = 0 ; i < l ; i++ ){
        if( !mymap[x+i][y+l].visited )
            mymap[x+i][y+l].c = f( x+i , y+l , m ,n );
    }

}

int main(){

    int m,n,i,j,k;
    char c;
    bool flag = false;

    while( scanf("%d%d",&m,&n) && m !=0 ){

        if( flag )
            printf("\n");
        flag = true;

        scanf("%c",&c);

        for( i = 0 ; i < m ; i++ ){
            for( j = 0 ; j < n; j++ ){
                scanf("%c",&mymap[i][j].c);
                if(mymap[i][j].c=='?'){
                    mymap[i][j].c = 'A';
                    mymap[i][j].visited = false;
                }
                else{
                    mymap[i][j].visited = true;
                }
            }
            scanf("%c",&c);
        }

        for( i = 0 ; i < m ; i++ ){
            for( j = 0 ; j < n; j++ ){
                if( !mymap[i][j].visited ){
                    mymap[i][j].visited = true;
                    mymap[i][j].c = f( i , j , m , n );
                    k = 1;
                    while( ( i+k < m ) && ( j+k < n ) && check( i , j , k , mymap[i][j].c ) ) {
                        mark( i , j , k , mymap[i][j].c );
                        k++;
                    }
                    f2( i , j , k , m , n );
                }
            }
        }
        for( i = 0 ; i < m ; i++ ){
            for( j = 0 ; j < n; j++ ){
                    printf("%c",mymap[i][j].c);
            }
            printf("\n");
        }

    }


    return 0;
}
