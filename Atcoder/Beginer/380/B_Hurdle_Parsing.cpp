#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int sum = 0;
  for (int i = 1; i < s.length(); i++)
  {
    if(s[i]=='|'){
      cout << sum << " ";
      sum = 0;
    }else{
      sum++;
    }
  }
  
}