#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e6;
bool ok = 1;

ll binpow(ll a, ll b) {
  if (b == 0)
      return 1;
  ll res = binpow(a, b / 2);
  if (b % 2){
      if(res*res*a>=1e6) ok = 0;
      return ((((res%mod) * (res%mod))%mod)* (a%mod))%mod;
  }
  else
      return ((res%mod) * (res%mod))%mod;
}

int main(){
  ll a,b;
  cin >> a >> b;
  string temp = to_string(binpow(a,b));
  string s = "";
  if(!ok){
    for (int i = 0; i < 6-(int)temp.length(); i++)
    {
      s+='0';
    }
    s+=temp;
  }else{
    s = temp;
  }
  cout << s << '\n';
}