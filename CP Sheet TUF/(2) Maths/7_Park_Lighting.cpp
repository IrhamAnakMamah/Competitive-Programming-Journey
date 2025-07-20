/*
Author : Irham
Date : 6 October 2024
Problem : Park Lighting
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,ans = 0;
    cin >> n >> m;
    if(n%2==1 && m%2==1){
      ans = ((n*m)/2)+1;
    }else{
      ans = (n*m)/2;
    }
    cout << ans << "\n";
  }
  
}