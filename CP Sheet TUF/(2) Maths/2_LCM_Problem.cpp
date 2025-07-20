/*
Author : Irham
Date : 6 October 2024
Problem : LCM Problem
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int l,r,x=0,y=0;
    cin >> l >> r;
    x = ((l*2<=r)? l:-1);
    y = ((l*2<=r)? l*2:-1);
    cout << x << " " << y << " \n";
  }
  
}