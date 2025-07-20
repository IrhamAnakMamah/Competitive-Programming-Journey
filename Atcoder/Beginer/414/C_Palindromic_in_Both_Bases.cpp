#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

bool cek (string s, ll temp){
  bool ok = 1;
  for (int i = 0; i < (int)s.length()/2; i++)
  {
    if(s[i] != s[s.length()-i-1]){
      ok = 0;
    }
  }
  string tes = to_string(temp);
  for (int i = 0; i < (int)tes.length()/2; i++)
  {
    if(tes[i] != tes[tes.length()-i-1]){
      ok = 0;
    }
  }
  
  return ok;
}

int main(){
  ll n,m;
  cin >> n >> m;

  string s = "1";
  ll temp = 1;
  ll ans = 1;
  while (temp<m && temp<10000000)
  {
    bool tambah = 0;
    int index = (int)s.length();
    temp++;
    s[index-1]+=1;
    for (int i = index - 1; i >= 0; i--)
    {
      if(s[i] - '0' == n){
        s[i] = '0';
        if(i == 0){
          tambah = 1;
          s[i] = '1';
        }else{
          s[i-1]+=1;
        }
      }
    }
    if(tambah){
      string tambah = "0";
      s+=tambah;
    }
    if(cek(s,temp)){
      ans+=temp;
    }
  }
  cout << ans << endl;
}