#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
  return (b==0 ? a : gcd(b,a%b));
}

int main(){
  int n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a,a+n);
  ll div = a[0];
  for (int i = n-1; i > 0; i--)
  {
    div = gcd(a[i],div);
  }

  ll cnt = 0;
  for (int i = 1; i <= sqrt(div); i++)
  {
    if(div%i==0){
      if(i==(div/i)){
        cnt++;
      }else{
        cnt+=2;
      }
    }
  }
  
  cout << cnt << "\n";
}