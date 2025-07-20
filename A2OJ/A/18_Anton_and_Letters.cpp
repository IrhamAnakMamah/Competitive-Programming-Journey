/*
Author : Irham
Date : 9 October 2024
Problem : Anton and Letters
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  string s;
  set<char> a;
  getline(cin,s);
  for (int i = 1; i < s.length()-1; i+=3)
  {
    a.insert(s[i]);
  }
  cout << a.size() << "\n";
}