#include <bits/stdc++.h>
using namespace std;

int main(){
  string x,y;
  cin >> x >> y;
  string s = (x.length()>=y.length() ? x : y);
  string t = (x.length()<y.length() ? x : y);
  int sum = s.length() - t.length();
  int temp = 0;
  int j = -1;
  for (int i = sum; i < s.length(); i++)
  {
    j++;
    if(s[i] == t[j]){
      continue;
    }else{
      temp = (i-sum+1)*2;
    }
  }
  cout << sum+temp << "\n";
}