/*
Author : Irham
Date : 6 October 2024
Problem : Minimal Square
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b;
    cin >> a >> b;
    int temp = min(a,b);
    if(temp*2>=a && temp*2>=b){
      cout << (temp*2)*(temp*2) << "\n";
    }else{
      cout << max(a,b)*max(a,b) << "\n";
    }
  }
  
}