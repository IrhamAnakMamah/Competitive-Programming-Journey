#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < n; i++)
    {
      ans += '+';
    }
    
    int cnt = 0;
    int k = 0;
    int i = 0;
    int j = n-1;
    while (i<=j && k < q)
    {
      if(s[k] == '0'){
        ans[i] = '-';
        i++;
      }else if(s[k] == '1'){
        ans[j] = '-';
        j--;
      }else{
        cnt++;
      }
      k++;
    }

    bool ok = 0;
    while (cnt != 0 && i <= j)
    {
      if(cnt == 2){
        ans[i] = '-';
        ans[j] = '-';
      }else if((i == j)){
        ans[i] = '-';
        ans[j] = '-';
      }else{
        ok = 1;
        ans[i] = '?';
        ans[j] = '?';
      }
      i++;
      j--;
    }
    
    cout << ans << endl;
  }
  
}