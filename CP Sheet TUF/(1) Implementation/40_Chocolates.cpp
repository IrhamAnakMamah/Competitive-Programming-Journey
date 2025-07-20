/*
Author : Irham
Date : 5 October 2024
Problem : B. Chocolates
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll ans = a[n-1], temp = a[n-1];
  for (int i = n-2; i >= 0; i--)
  {
    // cout << temp << endl;
    if(temp == 0) break;
    if(temp <= a[i]){
      temp--;
    }else{
      temp = a[i];
    }
    ans+=temp;
  }
  
  cout << ans << endl;

}