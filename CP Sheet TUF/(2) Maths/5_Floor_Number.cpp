/*
Author : Irham
Date : 6 October 2024
Problem : Floor Number
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,x;
    cin >> n >> x;
    if(n<=2){
      cout << 1 << "\n";
    }else{
      int i = 2;
      int temp = 2;
      while(true){
        temp += x;
        if(temp >= n){
          cout << i << "\n";
          break;
        }
        i++;
      }
    }
  }
  
}