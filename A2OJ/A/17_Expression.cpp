/*
Author : Irham
Date : 9 October 2024
Problem : Game With Sticks
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int a,b,c;
  int ans;
  cin >> a >> b >> c;
  // if(a == 1){
  //   if(b==1 && c==1){
  //     ans = 3;
  //   }else if(c==1){
  //     ans = a+b+c;
  //   }else{
  //     ans = (a+b)*c;
  //   }
  // }else if(b==1){
  //   ans = max((a+b)*c, a*(b+c));
  // }else if(c==1){
  //   ans = a*(b+c);
  // }else{
  //   ans = a*b*c;
  // }

  cout << max(a+b+c,max((a+b)*c,max(a*(b+c),a*b*c))) << "\n";
}