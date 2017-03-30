#include <stdio.h>

int main(){

    long long bishops[35][35*35];
    int n,k,i,j;

    for( i = 1 ; i <= 35 ; i++ ){
        for( j = 0 ; j <= i*2 ; j++ ){
            if( j == 0 )
                bishops[i][j] = 1;
            else
                bishops[i][j] = bishops[i-1][j]+bishops[i][j-1]
        }
    }

}
