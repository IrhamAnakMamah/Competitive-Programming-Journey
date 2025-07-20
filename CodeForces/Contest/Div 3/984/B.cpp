#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    vector<int> a(k, 0);
    for (int i = 0; i < k; i++)
    {
      int x,y;
      cin >> x >> y;
      a[x-1]+=y;
    }
    sort(a.begin(),a.end(), greater<>());
    int ans = 0;
    for (int i = 0; i < min(n,k); i++)
    {
      if(a[i]==0) break;
      ans+=a[i];
    }
    cout << ans << endl;
  }
  
}