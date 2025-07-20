/*
Author : Irham
Date : 9 October 2024
Problem : Even Odds
*/
#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main (){
  ll n,k,ans = 0;
  cin >> n >> k;
  ll temp = ceil((double)n/2);
  if(k<=temp){
    ans = 1;
    k--;
    while(k--){
      ans+=2;
    }
  }else{
    ans = 2;
    k = k - temp - 1;
    while (k--)
    {
      ans+=2;
    }
  }
  cout << ans << "\n";
}