#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<ll> a;
int test = 0;

int main(){
  cin >> n;
  a.resize(n);

  vector<ll> dp1(n+1, -1);
  vector<ll> dp2(n+1, -1);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  dp1[0] = 0;
  dp2[0] = a[0];
  for (int i = 1  ; i < n; i++)
  {
    dp1[i] = max(dp1[i-1], dp2[i-1] + a[i] * 2);
    dp2[i] = max(dp2[i-1], dp1[i-1] + a[i]);
  }
  
  cout <<  max(dp1[n-1], dp2[n-1])<< endl;
}