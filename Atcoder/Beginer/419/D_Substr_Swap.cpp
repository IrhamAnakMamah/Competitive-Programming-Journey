#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  string s,t;
  cin >> s >> t;

  vector<int> dist(n+1, 0);
  for (int i = 0; i < m; i++)
  {
    int a,b;
    cin >> a >> b;
    dist[a-1]++;
    dist[b]--;
  }
  
  vector<int> pref(n+2, 0);
  for (int i = 1; i <= n; i++)
  {
    pref[i] = pref[i-1] + dist[i-1];
  }
  // pref[i+1] = s[i]
  // pref[1+1] = s[1]

  string ans = s;
  for (int i = 0; i < n; i++)
  {
    if(pref[i+1]%2==0){
      ans[i] = s[i];
    }else{
      ans[i] = t[i]; 
    }
  }
  cout << ans << endl;
  
}