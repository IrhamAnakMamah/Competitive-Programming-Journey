#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  for (int i = 0; i < q; i++)
  {
    string t;
    cin >> t;

    int ok = -1;
    for (int j = 0; j < n; j++)
    {
      if(ok == -1 && t == s[j]){
        ok = j+1;
        break;
      }
    }
    cout << ok << endl;
  }
  
  
}