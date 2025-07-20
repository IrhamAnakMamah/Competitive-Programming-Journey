#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int i,int n, ll a[], ll sum1, ll sum2){
  if(i==n){
    return abs(sum1-sum2);
  }

  ll x = f(i+1,n,a,sum1+a[i],sum2);
  ll y = f(i+1,n,a,sum1,sum2 + a[i]);
  

  return min(x,y);
}

int main(){
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ll mn = f(0,n,a,0,0);
  cout << mn << "\n";
}