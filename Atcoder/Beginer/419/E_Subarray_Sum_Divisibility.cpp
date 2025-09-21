#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,l;
  cin >> n >> m >> l;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  queue<int> cache;
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
    if(i >= (l-1)){
      cache.push(sum);
      sum -= a[i-(l-1)];
    }
  }
  cache.push(sum);
  
  vector<int> dp(n+1, 0);
  queue<int> sisa;
  sisa.push(m-(cache.front()%m));
  int temp = sisa.front();
  for (int i = 0; i < l; i++)
  {
    dp[i] = temp;
  }
  cache.pop();
  
  for (int i = l; i < n; i++)
  {
    if(i >= l+l-1){
      temp -= sisa.front();
      sisa.pop();
    }
    int pilihan = m-(cache.front() % m);
    pilihan = abs(temp - pilihan);
    pilihan %= m;
    int temp2 = pilihan;
    queue<int> wow = sisa;
    int k = i-l;
    while (!wow.empty())
    {
      temp2 = temp2 + wow.front();
      temp2 %= m;
      pilihan = min(temp2, pilihan);
    }
    

    cache.pop();
  }
  // cout << dp[n-1] << endl;
  
}