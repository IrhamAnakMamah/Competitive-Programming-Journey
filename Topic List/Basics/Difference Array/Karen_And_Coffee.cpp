/*
Author : Irham
Date : 6 October 2024
Problem : B. Chocolates
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a(200002,0);

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k,q;
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;
    a[x] += 1;
    a[y+1] -= 1;
  }
  
  for (int i = 1; i < 200002; i++)
  {
    a[i] += a[i-1];
  }

  for (int i = 1; i < 200002; i++)
  {
    if(a[i]>=k){
      a[i]=1;
    }else{
      a[i]=0;
    }
    a[i] += a[i-1];
  }
  
  for (int i = 0; i < q; i++)
  {
    int x,y;
    cin >> x >> y;
    cout << a[y] - a[x-1] << endl;
  }
  
}