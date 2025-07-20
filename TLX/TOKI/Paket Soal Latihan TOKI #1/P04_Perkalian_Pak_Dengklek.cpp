#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  int ans = 0;
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++)
  {
    for (int j = 0; j < b.length(); j++)
    {
      ans+=(a[i]-'0')*(b[j]-'0');
    }
  }
  cout << ans << "\n";
}