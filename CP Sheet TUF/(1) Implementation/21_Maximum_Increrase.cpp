/*
Author : Irham
Date : 5 October 2024
Problem : Maximum Increase
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,a,ans = 1,temp = 0,count = 1;
  cin >> n >> a;
  temp = a;
  for (int i = 1; i < n; i++)
  {
    cin >> a;
    if(a>temp){
      count++;
      ans = max(count,ans);
    }else count = 1;

    temp = a;
  }
  cout << ans << endl;
}