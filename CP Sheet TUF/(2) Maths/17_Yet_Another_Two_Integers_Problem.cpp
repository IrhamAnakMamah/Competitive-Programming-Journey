/*
Author : Irham
Date : 8 October 2024
Problem : Yet Another Two Integers Problem
*/
#include<bits/stdc++.h>
using namespace std;
 
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    if(n==m){
      cout << 0 << "\n";
      continue;
    }
    cout << abs(n-m)/10 + ((n-m)%10!=0) << "\n";
  }
  
}