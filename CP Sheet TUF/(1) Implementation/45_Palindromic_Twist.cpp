/*
Author : Irham
Date : 5 October 2024
Problem : Palindromic Twist
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
    string s;
    bool ok = 1;
    cin >> n >> s;

    for (int i = 0; i < n/2; i++)
    {
      int temp = abs(s[i]-s[n-1-i]);
      if(s[i] == s[n-1-i] || (temp==2 || temp==0)){
        ok = 0;
      }else{
        ok = 1;
        break;
      }
    }
    
    if(ok){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }
  
}