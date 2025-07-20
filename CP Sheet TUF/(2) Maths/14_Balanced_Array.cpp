/*
Author : Irham
Date : 7 October 2024
Problem : Balanced Array
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,temp1 = 0, temp2 = 0;
    cin >> n;
    if(n%4!=0){
      cout << "NO" << "\n";
    }else{
      cout << "YES" << "\n";
      for (int i = 2; i <= n; i+=2)
      {
        cout << i << " ";
        temp1+=i;
      }
      for (int i = 1; i < n-2; i+=2)
      {
        cout << i << " ";
        temp2+=i;
      }
      cout << temp1 - temp2 << '\n';
    }
  }
  
}