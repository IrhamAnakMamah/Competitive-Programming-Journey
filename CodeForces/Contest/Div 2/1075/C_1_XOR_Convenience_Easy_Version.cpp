#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> ans(n+1, 0);
    vector<bool> vis(n+1, 0);
    ans[n-1] = 1;
    vis[1] = 1;
    if((n-1)&1){
      vis[n-2] = 1;
      ans[n] = n-2;
    }else{
      vis[n] = 1;
      ans[n] = n;
    }

    for (int i = n-2; i > 1; i--)
    {
      ans[i] = i ^ 1;
      vis[i^1] = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
      if(!vis[i]){
        ans[1] = i;
        break;
      }
    }
    
    for (int i = 1; i <= n; i++)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  
}