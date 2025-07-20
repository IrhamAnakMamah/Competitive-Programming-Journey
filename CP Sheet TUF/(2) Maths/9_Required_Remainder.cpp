/*
Author : Irham
Date : 6 October 2024
Problem : Required Remainder
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int x,y,n,ans = 0;
    cin >> x >> y >> n;
    ans = x*(n/x);
    if(ans + y > n){
      ans-=(x-y);
    }else{
      ans+=y;
    }
    cout << ans << endl;
  }
  
}