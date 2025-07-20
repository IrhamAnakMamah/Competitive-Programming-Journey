#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 1e5;
const ll mod = 1e9 + 7;
vector<vector<int>> C(MAXN+1,vector<int>(MAXN+1));

int main (){
  int t;
  cin >> t;
  ll a[t];
  ll b[t];
  for (int i = 0; i < t; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < t; i++)
  {
    cin >> b[i];
  }
  
  C[0][0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int k = 1; k < i; k++)
      C[i][k] = ((C[i][k-1] % mod) + (C[i - 1][k - 1] % mod))%mod;
  }

  for (int i = 0; i < t; i++)
  {
    cout << C[a[i]][b[i]]<< "\n";
  }
  
}