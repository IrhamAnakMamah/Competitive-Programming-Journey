/*
Author : Irham
Date : 6 October 2024
Problem : Balanced Rating Changes
Alternative
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }

  bool ok = 0;

  for(int i=0; i<n; i++)
  {
    float k=(double)a[i]/2;
    if((a[i]%2)!=0){
      a[i] = (ok ? ceil(k) : floor(k));
      ok^=1;
    }
    else
      a[i]=a[i]/2;
    cout << a[i] << endl;
  }
}