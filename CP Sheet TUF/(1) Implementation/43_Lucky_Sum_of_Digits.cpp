/*
Author : Irham
Date : 5 October 2024
Problem : Lucky Sum of Digits
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n;
  cin >> n;
  int a = 0, b = 0;

  while (n>=0)
  {
    if(n%7==0){
      b = n/7;
      n = 0;
      break;
    }
    a++;
    n-=4;
  }
  
  if(n==0){
    while(a--){
      cout << "4";
    }
    while (b--)
    {
      cout << "7";
    }
  }else{
    cout << -1;
  }
  cout << endl;
}