#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int x){
  ll res = 1;
  for(int i = 0; i < x; i++)
    res *= 10;
  return res;
}

int main(){
  int q;
  cin >> q;
  while (q--)
  {
    ll n;
    cin >> n;
    n--;
    if(n<9){
      cout << n+1 << endl;
    }else{
      int l = 1;
      ll pp = 0;
      while(9*f(l-1)*l<n){
        pp = f(l-1);
        n-=9*pp*l;
        l++;
      }
      pp = f(l-1);
      string ans = to_string(pp + n/l);
      cout << ans[n%l] << endl;
    }
  }
}