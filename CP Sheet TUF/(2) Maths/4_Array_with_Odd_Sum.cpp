/*
Author : Irham
Date : 6 October 2024
Problem : Array with Odd Sum
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >>t;
  while (t--)
  {
    int n,a;
    int b = 0,c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      if(a%2==1){
        c++;
      }else{
        b++;
      }
    }
    if((b==0 && c%2==0) || (b>0 && c==0)){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
  
}