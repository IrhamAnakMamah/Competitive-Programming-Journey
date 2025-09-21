#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> a;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '1'){
      a.push_back(i+1);
    }
  }

  if(a.size() == 1){
    cout << 0 << endl;
  }else{
    ll ans = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
      ll temp = 0;
      int idx = 1;
      for (int j = i-1; j >= 0; j--)
      {
        temp+=(a[i]-idx)-a[j];
        idx++;
      }
      idx = 1;
      for (int j = i+1; j < a.size(); j++)
      {
        temp+=a[j]-(a[i]+idx);
        idx++;
      }
      ans = min(temp, ans);
    }
    cout << ans << endl;
  }
  
}