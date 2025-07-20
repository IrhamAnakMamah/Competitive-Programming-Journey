/*
Author : Irham
Date : 9 October 2024
Problem : Game With Sticks
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n,m;
  cin >> n >> m;
  int temp = (n>m) ? (n*m)/n : (n*m)/m;

  if(temp%2==0){
    cout << "Malvika" << "\n";
  }else{
    cout << "Akshat" << "\n";
  }
}