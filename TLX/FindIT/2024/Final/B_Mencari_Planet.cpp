#include <bits/stdc++.h>
using namespace std;

char vokal[5] = {'a','i','u','e','o'};

int main(){
  vector<bool> huruf(27,0);
  for (int i = 0; i < 5; i++)
  {
    huruf[vokal[i]-'a'] = 1;
  }
  
  int n;
  cin >> n;
  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int sz = s[i].length();
    bool cek = 1;
    if(sz > 1){
      string temp = s[i].substr(0,2);
      int total = huruf[temp[0]-'a'] + huruf[temp[1]-'a'];

      cek = (total<2);
      
      temp = s[i].substr(sz-2,2);
      total = huruf[temp[0]-'a'] + huruf[temp[1]-'a'];
      
      if(cek){
        cek = (total<2);
      }
    }
    if(cek){
      for (int j = 2; j < sz; j++)
      {
        int hitung = 0;
        bool tentu = huruf[s[i][j]-'a'];
        if(huruf[s[i][j-1]-'a'] == tentu && huruf[s[i][j-2]-'a'] == tentu){
          cek = 0;
        }
      }
    }
    ans += cek;
  }

  cout << ans/__gcd(ans,n) << " " << n/__gcd(ans,n) << endl;

}