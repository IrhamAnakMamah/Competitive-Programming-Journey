#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,m;
    int total = 0;
    cin >> n >> m;
    vector<bool> a(102,0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      if(!a[x]){
        total++;
        a[x] = 1;
        ans.push_back(i+1);
      }
    }
    if(total>=m){
      cout << "YES" << endl;
      for (int i = 0; i < m; i++)
      {
        cout << ans[i] << " ";
      }
      cout << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}