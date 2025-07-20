/*
Author : Irham
Date : 9 October 2024
Problem : Game With Sticks
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,m,ans = INT_MAX;
  cin >> n >> m;
  int a[m];
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
  }
  sort(a,a+m);
  for (int i = 0; i <= m-n; i++)
  {
    int b[n];
    int k = 0;
    for (int j = i; j < n+i; j++)
    {
      b[k]=a[j];
      k++;
    }
    ans = min(ans,b[n-1]-b[0]);
  }
  cout << ans << "\n";
}