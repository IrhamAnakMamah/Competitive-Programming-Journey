/*
Author : Irham
Date : 5 October 2024
Problem : Middle of the Contest
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  string s,t,ans = "";
  string bantu1 = "",bantu2 = ""; 
  cin >> s >> t;
  int a,b,total;
  a = stoi(s.substr(0,2),nullptr,10);
  b = stoi(s.substr(3,2),nullptr,10);

  total = (((t[0] - s[0])*10 + (t[1]- s[1]))*60 + (t[3]- s[3])*10 + (t[4]- s[4]))/2;

  if(a+(total/60)+(total%60+b>=60)<10){
    bantu1 = "0";
  }
  if(((total%60+b)%60)<10){
    bantu2 = "0";
  }
  ans = bantu1 + to_string(a+(total/60)+(total%60+b>=60)) + ":" + bantu2 + to_string((total%60+b)%60);

  cout << ans << endl;
}