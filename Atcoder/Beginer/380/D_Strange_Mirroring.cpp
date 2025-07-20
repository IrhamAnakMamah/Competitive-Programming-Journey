#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin >> s;
  int q;
  cin >> q;
  ll sz = (ll)s.length();
  for (int i = 0; i < q; i++)
  {
    ll k;
    cin >> k;
    k--;
    ll x = k%sz;
    ll temp = k/sz;
    ll cnt = 0;
    while (temp!=0)
    {
      if(temp&1){
        cnt++;
      }
      temp/=2;
    }
    if(cnt&1){
      if(s[x]<='Z'){
        char c = s[x]+('a'-'A');
        cout << c << " ";
      }else{
        char c = s[x]-('a'-'A');
        cout << c << " ";
      }
    }else{
      cout << s[x] << " ";
    }
  }
  cout << endl;
}