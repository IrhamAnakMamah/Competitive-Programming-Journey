/*
Author : Irham
Date : 9 October 2024
Problem : I Wanna Be the Guy
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int n, p, a;
  cin >> n >> p;
  set<int> ans;
  for (int i = 0; i < p; i++)
  {
    cin >> a;
    ans.insert(a);
  }
  cin >> p;
  for (int i = 0; i < p; i++)
  {
    cin >> a;
    ans.insert(a);
  }

  if(ans.size()==n){
    cout << "I become the guy." << "\n";
  }else{
    cout << "Oh, my keyboard!" << '\n';
  }
}