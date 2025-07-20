/*
Author : Irham
Date : 6 October 2024
Problem : Magical Sticks
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << (n%2==1 ? n/2 + 1 : n/2) << "\n";
  }
  
}