#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int a[MAXN];

vector<vector<int>> dp;

int aa = 1;

int f(int x, int langkah, int kena){
  if(langkah == n){
    if(a[langkah-1] != x){
      return 1;
    }else{
      return 0;
    }
  }

  if(dp[langkah][kena] != -1){
    return dp[langkah][kena];
  }

  int ans = 0;
  if(kena == 2){
     
  }else if(a[langkah-1] != x){
    ans = 1 + f(x+1, langkah+1, 1);
    ans = min(ans, 1 + f(1, langkah+1 , 0));  
  }else{
    ans = f(x+1, langkah+1, 0);
    ans = min(ans, f(1, langkah+1, 0));
  }

  return dp[langkah][kena] = ans;
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  dp.resize(n+1, vector<int>(2, -1));
  
  int ans = f(1,1, 2);
  cout << ans << endl;
}