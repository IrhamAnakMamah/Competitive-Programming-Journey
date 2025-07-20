/*
Author : Irham
Date : 5 October 2024
Problem : Diverse Substring
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n;
  cin >> n;
  string s,ans;
  cin >> s;

  bool ok = 0;

  for (int i = 0; i < n-1; i++)
  {
    if(s[i]!=s[i+1]){
      ok = 1;
      ans+=s[i];
      ans+=s[i+1];
      break;
    }
  }
  
  if(ok){
    cout << "YES" << endl;
    cout << ans << endl;
  }else{
    cout << "NO" << endl;
  }
}