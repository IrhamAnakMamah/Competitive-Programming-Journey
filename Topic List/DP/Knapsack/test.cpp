#include <bits/stdc++.h>
using namespace std;

// a itu harga dan b itu lembar, ditanyanya berapa banyak max lembar yang bisa didapat
int a[1001], b[1001];

vector<vector<int>> dp(1001, vector<int>(1001,-1));

int main(){
  int n,m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  dp[0][0] = 0;
  for (int i = 0; i < n; i++)
  {
    
  }
  
  cout << ans << endl;

}