#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  int ans = -1;
  cin >> n >> m;
  int a[n];
  vector<int> b(m+1,0);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    b[a[i]]++;
  }
  
  for (int i = 1; i <= m; i++)
  {
    if(b[i]==0){
      ans = 0;
    }
  }
  
  if(ans==-1){
    ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
      b[a[i]]--;
      ans++;
      if(b[a[i]]==0){
        break;
      }
    }
    cout << ans << endl;
  }else{
    cout << ans << endl;
  }
}