/*
Author : Irham
Date : 7 October 2024
Problem : Buy a Shovel
*/
#include<bits/stdc++.h>
using namespace std;
 
int main ()
{
  int k,r;
  cin >> k >> r;
  int temp = 0;
  int ans;

  for (int i = 1; i < INT_MAX; i++)
  {
    temp = k*i;
    if(temp%10==r){
      ans = i;
      break;
    }else if(temp%10==0){
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;

}