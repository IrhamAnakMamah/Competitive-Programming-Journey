#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  vector<int> ans;
  vector<int> jawab(n+1, 0);
  vector<vector<bool>> cek(n+1, vector<bool>(m+1, 0));
  for (int i = 0; i < k; i++)
  {
    int a,b;
    cin >> a >> b;
    if(!cek[a][b]){
      cek[a][b] = 1;
      jawab[a]++;
    }

    if(jawab[a] == m){
      ans.push_back(a);
    }
  }
  
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}