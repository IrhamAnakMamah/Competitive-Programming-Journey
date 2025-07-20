/*
Author : Irham
Date : 7 October 2024
Problem : Most Unstable Array
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,m;
    cin >> n >> m;
    if(n==1){
      cout << 0 << "\n";
    }else{
      if(n==2){
        cout << m << "\n";
      }else{
        cout << m*2 << "\n";
      }
    }
  }
  
}