#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
  
    int cnt = 0;
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      mp[a]++;
      cnt = max(cnt,mp[a]);
    }
    cout << max(0, ((n/2)+1) - cnt) << endl;
  }
  
}