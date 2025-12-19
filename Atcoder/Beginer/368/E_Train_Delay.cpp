#include <bits/stdc++.h>
using namespace std;

struct train{
  int u, v, sampai, tiba;
};

int main(){
  int n,m,x;
  cin >> n >> m >> x;

  vector<train> adj(n+1);
  vector<bool> vis(n+1, 0);
  vector<int> d(n+1, 0);

  int temp = 0;
  int start = 0;

  int ans[m];

  for (int i = 0; i < m; i++)
  {
    int a,b,c,e;
    cin >> a >> b >> c >> e;

    if(i == 0){
      temp = e + x;
      d[b] = temp;
    }else{
      if(d[b] != 0){
        ans[i] = 0;
      }else{
        if(d[a] > c){
          ans[i] = d[a] - c;
          d[b] = e + ans[i];
        }else{
          ans[i] = 0;
          d[b] = e;
        }
      }
    }
  }

  for (int i = 1; i < m; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  
  
}