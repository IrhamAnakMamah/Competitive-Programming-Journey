/*
Author : Irham
Date : 8 October 2024
Problem : Divisibility Problem
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
    cout << (n%m == 0 ? 0 : ((n/m)+1)*m - n) << "\n";
  }
  
}