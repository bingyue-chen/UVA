#include<stdio.h>
#include<iostream>
#include<algorithm>
#include <vector>

void setnum( int *dice , int *num );
int cate1( int *num );
int cate2( int *num );
int cate3( int *num );
int cate4( int *num );
int cate5( int *num );
int cate6( int *num );
int cate7( int *num );
int cate8( int *num );
int cate9( int *num );
int cate10( int *num );
int cate11( int *num );
int cate12( int *num );
int cate13( int *num );

using namespace std;

int main(){

    int dice[5],num[6],t,i,scoremap[13][13],score;

    t = 0;

    while( scanf("%d%d%d%d%d",&dice[0],&dice[1],&dice[2],&dice[3],&dice[4]) != EOF ){

        t++;

        setnum( dice , num );


        for( i = 0 ; i < 13 ; i++ ){

            switch( i ){
                case 0:
                    score = cate1( num );
                    break;
                case 1:
                    score = cate1( num );
                    break;
                case 2:
                   score = cate2( num );
                    break;
                case 3:
                    score = cate3( num );
                    break;
                case 4:
                    score = cate4( num );
                    break;
                case 5:
                    score = cate5( num );
                    break;
                case 6:
                    score = cate6( num );
                    break;
                case 7:
                    score = cate7( num );
                    break;
                case 8:
                    score = cate8( num );
                    break;
                case 9:
                    score = cate9( num );
                    break;
                case 10:
                    score = cate10( num );
                    break;
                case 11:
                    score = cate11( num );
                    break;
                case 12:
                    score = cate12( num );
                    break;

            }
            scoremap[t][i] = score;
        }

        /*for( vector<node>::iterator it =  nodevector.begin() ; it != nodevector.end(); it++ ){
            cout << (*it).score <<endl;
        }*/



        if( t == 13){

            t = 0;



        }
    }

    return 0;
}

void setnum( int *dice , int *num ){

    int i;

    for( i = 0 ; i < 6 ; i++ ){
        num[i] = 0;
    }

    for( i = 0 ; i < 5 ; i ++ ){
        num[dice[i]-1]++;
    }

}

int cate1( int *num ){
    return num[0];
}
int cate2( int *num ){
    return 2*num[1];
}
int cate3( int *num ){
    return 3*num[2];
}
int cate4( int *num ){
    return 4*num[3];
}
int cate5( int *num ){
    return 5*num[4];
}
int cate6( int *num ){
    return 6*num[5];
}
int cate7( int *num ){
    return num[0]+2*num[1]+3*num[2]+4*num[3]+5*num[4]+6*num[5];
}
int cate8( int *num ){

    for( int i = 0 ; i < 6 ; i++ ){
        if( num[i] >=3 ) return cate7( num );
    }

    return 0;

}
int cate9( int *num ){

    for( int i = 0 ; i < 6 ; i++ ){
        if( num[i] >=4 ) return cate7( num );
    }

    return 0;

}
int cate10( int *num ){

    for( int i = 0 ; i < 6 ; i++ ){
        if( num[i] ==5 ) return 50;
    }

    return 0;

}
int cate11( int *num ){

    int i = 0;
    while( num[i] == 0 ) i++;

    int j = 0;
    while( j < 6 && num[i] > 0 ){
        i++;
        j++;
        if( j == 4 ) return 25;
    }

    return 0;

}
int cate12( int *num ){

    int i = 0;
    while( num[i] == 0 ) i++;

    int j = 0;
    while( j < 6 && num[i] > 0 ){
        i++;
        j++;
        if( j == 5 ) return 35;
    }

    return 0;

}
int cate13( int *num ){

    int i,c3,c2;

    for( i = c3 = c2 = 0; i < 6 ; i++ ){
        if( num[i] == 3 )c3++;
        else if( num[i] == 2 ) c2++;
    }

    if( c3 == 1 && c2 == 1 ) return 40;

    return 0;

}
