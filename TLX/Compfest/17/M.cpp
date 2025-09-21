#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int ans = 0;
  cin >> n;
  string s;
  cin >> s;

  if(n&1){
    ans++;
    int i = n/2-1;
    int jumlah1 = 1;
    int j = n/2+1;
    for (int xx = 0; xx < n/2; xx++)
    {
      if(s.substr(i-jumlah1+1, jumlah1) == s.substr(j, jumlah1)){
        ans+=2;
        i -= jumlah1;
        j += jumlah1;
        jumlah1 = 1;
      }else{
        jumlah1++;
      }
    }
    cout << ans << endl;
  }else{
    int i = n/2-1;
    int jumlah1 = 1;
    int j = n/2;
    for (int xx = 0; xx < n/2; xx++)
    {
      if(s.substr(i-jumlah1+1, jumlah1) == s.substr(j, jumlah1)){
        ans+=2;
        i -= jumlah1;
        j += jumlah1;
        jumlah1 = 1;
      }else{
        jumlah1++;
      }
    }
    if(ans==0){
      ans = 1;
    }
    cout << ans << endl;
  }
}