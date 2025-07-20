#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string ans = "A";
  for (int i = 1; i <= n-1; i++)
  {
    char c = 'A'+i;
    string x;
    x = c;
    ans = ans + x + ans;
  }
  
  cout << ans;
}