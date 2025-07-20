/*
Author : Irham
Date : 19 October 2024
Problem : Valera and X
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s[n];
  set<char> a,b;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  int k = 0;
  bool turun = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(j == k || j == n-k-1){
        a.insert(s[i][j]);
      }else{
        b.insert(s[i][j]);
      }
    }
    if(i == (n/2)){
      turun = 1;
      k--;
    }else if(!turun){
      k++;
    }else{
      k--;
    }
  }
  
  if((a.size() == 1 && b.size() == 1) && *a.begin() != *b.begin()){
    cout << "YES\n";
  }else{
    cout << "NO\n";
  }
}