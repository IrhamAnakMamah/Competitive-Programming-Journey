#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int target = k-1;
  string nol = "";
  string satu = "";
  string ans = "";
  bool ok = 0;
  bool cek = 0;
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if(count==k-1 && (s[i-1]=='1' && s[i]=='0')){
      ok = 0;
      count++;
      ans+=satu;
      ans+=nol;
    }
    if(s[i]=='1'){
      ok = 1;
    }
    if(s[i]=='0' && ok){
      count++;
      ok = 0;
    }

    if(count==k-1){
      if(s[i]=='0')
      nol+=s[i];
      else{
        satu+=s[i];
        ok = 1;
      }
    }else{
      ans+=s[i];
    }
  }
  if(count==k-1){
    ok = 0;
    count++;
    ans+=satu;
    ans+=nol;
  }
  cout << ans << "\n";
}