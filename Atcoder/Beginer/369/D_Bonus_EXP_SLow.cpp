#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> a;
vector<pair<ll,bool>> dp;
int test = 0;

ll f(int x, int monster){
  if(x == n){
    return 0;
  }
  
  if(dp[x].first != -1 && dp[x].second == monster){
    return dp[x].first;
  }

  ll take = 0;
  ll nottake = 0;
  if(monster==1){
    take = (a[x]*2) + f(x+1, (monster+1)%2);
  }else{
    take = a[x] + f(x+1, (monster+1)%2);
  }
  nottake = f(x+1, monster);
  bool temp = (monster == 1);
  dp[x] = {max(take,nottake), temp};
  return dp[x].first;
  // return max(take,nottake);
}

int main(){
  cin >> n;
  a.resize(n);
  dp.resize(n, {-1,0});
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ll ans = f(0,0);
  cout << ans << endl;
}