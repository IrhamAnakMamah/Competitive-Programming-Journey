#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;

  int x = 0;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if(a&1){
      x++;
    }
  }
  if(x&1){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
  }
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  
  return 0;
}