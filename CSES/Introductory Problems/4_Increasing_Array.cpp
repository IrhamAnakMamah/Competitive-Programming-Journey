/*
Author : Irham
Date : 19 October 2024
Problem : Increasing Array
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,ans = 0;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++)
  {
    if(a[i]<a[i-1]){
      ans+=a[i-1]-a[i];
      a[i] = a[i-1];
    }
  }
  cout << ans << "\n";
}