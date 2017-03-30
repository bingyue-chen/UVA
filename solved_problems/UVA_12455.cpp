#include <iostream>
#define MAX 1003
using namespace std;
int f( int bars[MAX] , int sum , int l , int x , int n);
int main(){
    int t , l , n , bars[MAX];
    cin >> t;
    while( t-- ){
        cin >> l >> n;
        for( int i = 0 ; i < n ; i++ ){
            cin >> bars[i];
        }
        if( l == 0 ){
            cout << "YES" << endl;
        }
        else{
            if( f( bars , 0 , l , 0 , n ) == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
int f( int bars[MAX] , int sum , int l , int x , int n){
    if( sum > l){
        return 0;
    }
    else if( sum == l){
        return 1;
    }
    else{
        for( int i = x ; i < n ; i++ ){
            if( f( bars , sum + bars[i] , l , i + 1 , n ) == 1 ){
                return 1;
            }
        }
        return 0;
    }
}
