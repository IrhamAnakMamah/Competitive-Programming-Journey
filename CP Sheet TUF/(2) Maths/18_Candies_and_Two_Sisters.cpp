/*
Author : Irham
Date : 8 October 2024
Problem : Candies and Two Sisters
*/
#include<bits/stdc++.h>
using namespace std;
 
int main ()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if(n==1 || n==2){
      cout << 0 << "\n";
    }else{
      cout << n/2 - (n%2==0) << "\n";
    }
  }
  
}