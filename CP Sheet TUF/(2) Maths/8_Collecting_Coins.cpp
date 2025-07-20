/*
Author : Irham
Date : 6 October 2024
Problem : Collecting Coins
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    int temp = max(a,max(b,c));
    n = n-(temp - a + temp - b + temp - c);
    if(n%3==0 && n>=0){
      cout << "YES" << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }
  
}