#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int n = (int)s.length();
  int a = 0, b = 0, c = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i] == 'O')a++;
    if(s[i] == 'S')b++;
    if(s[i] == 'N')c++;
    if(s[i] == 'P' && a && b && c){
      ans = max(a+b+c, ans);
      ans++;
    }
  }
  cout << (!ans ? -1 : ans) << endl;
}