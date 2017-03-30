#include<stdio.h>
#define uprange 10000000

int prime_table[uprange];
int prime[664579];

void test(){
    int i , j;
    int c = 0;
    for( i = 2 ; i < uprange ; i++ ){
        if( !prime_table[i] ){
            prime[c++] = i;
            for( j = i*2 ; j < uprange ; j += i )
                prime_table[j] = 1;
        }
    }
}

int main(){

    int n,i,j;

    test();

    while( scanf("%d",&n) == 1 ){

        if( n >= 8 ){
            if( n%2 ){
                n = n - 5;
                j = 3;
            }
            else{
                n = n - 4;
                j = 2;
            }

            for( i = 0 ; i < 664579/2 ; i++ ){
                if( !prime_table[( n - prime[i] )] ){
                    printf("2 %d %d %d\n",j,prime[i],n-prime[i]);
                    break;
                }
            }


            if( i == 664579/2 ){
                printf("Impossible.\n");
            }
        }
        else{
            printf("Impossible.\n");
        }

    }


    return 0;
}
