#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    int a[n][m];
    int mx = 0;
    pair<int,int> index;
    int jumlah = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> a[i][j];
        mx = max(mx,a[i][j]);
      }
    }

    vector<int> x(n+1,0);
    vector<int> y(m+1,0);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(a[i][j] == mx){
          a[i][j] = 1;
          x[i]++;
          y[j]++;
          jumlah++;
        }else{
          a[i][j] = 0;
        }
      }
    }
    
    bool ok = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int temp = x[i] + y[j] - a[i][j];
        if(temp == jumlah){
          ok = 1;
        }
      }
      
    }
    if(ok){
      cout << mx - 1 << endl;
    }else{
      cout << mx << endl;
    }
  }
  
}