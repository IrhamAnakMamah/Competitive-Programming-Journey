/*
Author : Irham
Date : 6 October 2024
Problem : k-th divisor vjudge
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n,k;
  cin >> n >> k;
  set<ll> ans;
  ans.insert(1);
  for (int i = 2; i <= sqrt(n); i++)
  {
    ll temp = n;
    if(temp%i==0){
      ans.insert(i);
      while(temp%i==0){
        temp/=i;
        ans.insert(temp);
      }
    }
  }
  ans.insert(n);
  int j = 1;
  ll wow = -1;
  for(auto a:ans){
    if(j==k){
      wow = a;
      j++;
    }else j++;
  }

  cout << wow << endl;
}