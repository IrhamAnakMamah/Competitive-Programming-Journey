#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n+1, 0); // a[n+1];
  vector<int> b(n+1, 0);
  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
    if(b[i] == -1){

    }else{
      a[b[i]]++;
    }
  }
  
  bool ok = 1;
  for (int i = 1; i <= n; i++)
  {
    if(a[i] > 1){
      ok = 0;
      break;
    }
  }
  
  if(!ok){
    cout << "No" << endl;
  }else{
    int k = 1;
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++)
    {
      if(b[i]!=-1){
        cout << b[i] << " ";
      }else{
        while (k <= n)
        {
          if(a[k] != 1){
            cout << k << " ";
            k++;
            break;
          }else{
            k++;
          }
        }
        
      }
    }
    cout << endl;
    
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  
}