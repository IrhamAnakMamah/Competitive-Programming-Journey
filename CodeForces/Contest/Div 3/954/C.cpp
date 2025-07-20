#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    string s,t;
    cin >> n >> m;
    cin >> s;
    vector<bool> visit(n,0);
    for (int i = 0; i < m; i++)
    {
      int b;
      cin >> b;
      b--;
      visit[b] = 1;
    }
    cin >> t;
    sort(t.begin(), t.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if(visit[i] && cnt<m){
        s[i] = t[cnt];
        cnt++;
      }
    }
    cout << s << "\n";
  }
  
}