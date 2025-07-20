/*
Author : Irham
Date : 7 October 2024
Problem : Even Array
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,a,ans = 0,b = 0,c = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> a;
      if(a%2!=i%2){
        if(a%2==0){
          b++;
        }else{
          c++;
        }
        ans++;
      }
    }
    cout << ((b==c) ? ans/2 : -1) << "\n";
  }
  
}