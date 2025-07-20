/*
Author : Irham
Date : 6 October 2024
Problem : Twins
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,sum = 0, temp = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum+=a[i];
  }
  sort(a,a+n);
  for (int i = n-1; i >= 0; i--)
  {
    temp+=a[i];
    if(temp>sum-temp){
      cout << n-i << "\n";
      break;
    }
  }
  
}