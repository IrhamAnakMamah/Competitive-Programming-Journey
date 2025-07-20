/*
Author : Irham
Date : 6 October 2024
Problem : Balanced Rating Changes
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,count = 0,ans = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if(abs(a[i])%2==0){
      ans+=a[i]/2;
    }else{
      double temp = (double)a[i]/2;
      count++;
      ans+=ceil(temp);
    }
  }
  
  //floor = *ex -3,5 -> -4
  //ceil = *ex -3.5 - > -3

  // ans < 0,

  if(ans>0 && ans<=count){
    for (int i = 0; i < n; i++)
    {
      double temp = 0;
      if(abs(a[i])%2!=0 && ans!=0){
        temp = (double)a[i]/2;
        a[i] = floor(temp);
        ans--;
      }else{
        temp = (double)a[i]/2;
        a[i] = ceil(temp);
      }
      cout << a[i] << "\n";
    }
  }else{
    for (int i = 0; i < n; i++)
    {
      cout << ceil((double)a[i]/2) << "\n";
    }
  }
}