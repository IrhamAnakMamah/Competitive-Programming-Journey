#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    queue<int> q[n+1];
    vector<int> dp(n+1,0);
    for (int i = 1; i <= n; i++)
    {
      dp[i] = dp[i-1];
      int temp = a[i-1];
      q[temp].push(i);
      if(q[temp].size() > temp){
        q[temp].pop();
      }
      if(q[temp].size() == temp){
        dp[i] = max(dp[i], dp[q[temp].front() - 1] + temp);
      }
    }
    cout << dp[n] << endl;
  }
  
}