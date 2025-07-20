#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
      ones += s[i]-'0';
    }
    int zeros = n-ones;
    int ans = (zeros * (ones + 1)) + (ones * (ones-1));
    cout << ans << endl;

  }
  
}