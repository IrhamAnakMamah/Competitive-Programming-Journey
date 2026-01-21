#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  vector<bool> v1 (27, 0), v2(27, 0);

  for (int i = 0; i < n; i++)
  {
    v1[s[i] - 'a'] = 1;
  }

  for (int i = 0; i < m; i++)
  {
    v2[t[i] - 'a'] = 1;
  }  

  int q;
  cin >> q;

  // s = Takahashi
  // t = Aoki
  while (q--)
  {
    string temp;
    cin >> temp;

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    int x = 0, y = 0;

    for (int i = 0; i < temp.length(); i++)
    {
      x += v1[temp[i] - 'a'];
      y += v2[temp[i] - 'a'];
    }
    
    if(x > y){
      cout << "Takahashi" << endl;
    }else if(y > x){
      cout << "Aoki" << endl;
    }else{
      cout << "Unknown" << endl;
    }
  }
  
}