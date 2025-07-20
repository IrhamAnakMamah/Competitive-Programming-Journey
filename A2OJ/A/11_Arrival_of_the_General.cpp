/*
Author : Irham
Date : 6 October 2024
Problem : Arrival of the General
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,a,b,c;
  int temp1 = INT_MAX, temp2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if(temp1>=a){
      b = i+1;
      temp1 = a;
    }
    if(temp2<a){
      c = i+1;
      temp2 = a;
    }
  }
  if(b < c){
    cout << n-b + c - 2 << "\n";
  }else{
    cout << n-b + c-1 << "\n";
  }
}