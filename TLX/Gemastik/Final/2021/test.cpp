#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

vector<long long> trial_division1(long long n) {
  vector<long long> factorization;
  for (long long d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      factorization.push_back(d);
      n /= d;
    }
  }
  if (n > 1)
    factorization.push_back(n);
  return factorization;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> ans;
  ans = trial_division1(n);
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;
}