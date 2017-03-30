#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
  int t,need,purpose_num,purpose;

  cin >> t;

  while(t--){
    cin >> need >> purpose_num;
    int dp[1005] = {};
    dp[0] = 1;
    for( int i = 0; i < purpose_num ;i++){
        cin >> purpose;
        for( int j = need-purpose; j >= 0 ;j--){
            if(dp[j] &&  !dp[j+purpose])
                dp[j+purpose] = 1;
        }
    }
    if(dp[need])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
  }

  return 0;
}

