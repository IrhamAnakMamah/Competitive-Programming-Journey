#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int MOD = 998244353;

vector<int> f(MAXN, 0);
vector<int> c(MAXN, 0);

long long binpow(long long a, long long b) {
  if (b == 0)
      return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
      return res * res * a;
  else
      return res * res;
}

void calculate(){
  for (int i = 1; i <= MAXN; i++)
  {
    for (int j = i; j <= MAXN; j+=i)
    {
      f[i]+=c[j];
    }
    
  }
}

long long calculateRes(){
  long long res = 1;
  for (int i = 1; i <= MAXN; i++)
  {
    if(f[i]>1){
      cout << i << " " << f[i] << " ";
      long long pair = (1LL * (f[i] * (f[i]-1))/2) % MOD;
      cout << pair << endl;
      res = (res * binpow(f[i],pair)) % MOD;
    }
  }
  return res;
}

int main(){
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    c[x]++;
  }
  
  calculate();
  long long ans = calculateRes();
  cout << ans << "\n";
}