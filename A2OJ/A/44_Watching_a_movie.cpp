/*
Author : Irham
Date : 19 October 2024
Problem : Wathcing a movie
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x;
  cin >> n >> x;
  int time = 1;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int l,r;
    cin >> l >> r;
    time += ((l-time)/x) * x;
    ans += r-time+1;
    time = r+1;
  }
  cout << ans << "\n";
}