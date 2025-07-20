#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = "0" + s;
    int k = (1<<n);

    vector<bool> ok(k,0);
    ok[0] = 1;
    for (int i = 0; i < k; i++)
    {
      if(ok[i] == 0){
        continue;
      }else{
        for (int j = 0; j < n; j++)
        {
          if(i&(1<<j)){
            continue;
          }
          int next = (i|(1<<j));
          if(s[next] == '0'){
            ok[next] = 1;
          }
        }
        
      }
    }
    cout << (ok[k-1] ? "Yes" : "No") << endl;
  }
  
}