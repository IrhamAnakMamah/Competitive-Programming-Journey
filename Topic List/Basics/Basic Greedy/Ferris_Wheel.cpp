/*
Author : Irham
Date : 19 October 2024
Problem : Ferris Wheel
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,x;
  cin >> n >> x;
  int ans = 0;
  int a[n];
  for(int i = 0 ;i<n;i++){
    cin >> a[i];
  }
  sort(a,a+n);
  bool vis[n];
  memset(vis,0,n);
  int i = 0;
  int j = n-1;
  while (i<j)
  {
    if(a[i]+a[j]>x){
      j--;
    }else{
      ans++;
      vis[i]=1;
      vis[j]=1;
      j--;
      i++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if(!vis[i])ans++;
  }
  
  cout << ans << "\n";
}