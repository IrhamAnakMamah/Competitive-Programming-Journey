#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s[n];

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<string> ans;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(i!=j){
        string temp = s[i] + s[j];
        bool ok = 1;
        for (int c = 0; c < ans.size(); c++)
        {
          if(temp == ans[c]){
            ok = 0;
          }
        }
        if(ok){
          ans.push_back(temp);
        }
      }
    }
  }
  cout << ans.size() << endl;
  
}