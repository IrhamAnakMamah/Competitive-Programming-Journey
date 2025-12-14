#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int mid = (int)s.length();
  mid = (mid+1)/2;
  mid--;
  for (int i = 0; i < s.length(); i++)
  {
    if(mid != i){
      cout << s[i];
    }
  }
  cout << endl;
}