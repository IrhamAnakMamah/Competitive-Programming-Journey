#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> s;

int cek(int x, int y){
  if(y == m-1){
    return cek(x+1, 0);
  }
  if(x == n-1){
    return 0;
  }

  int ans = INT_MAX;
  
  if(s[x][y] == '#' && s[x+1][y] == '#' && s[x+1][y+1] == '#' && s[x][y+1] == '#'){
    if(y == 0){
      s[x+1][y+1] = '.';
      ans = min(ans, 1 + cek(x,y+1));
      s[x+1][y+1] = '#';
    }else if(y == m-2){
      s[x+1][y] = '.';
      ans = min(ans, 1 + cek(x,y+1));
      s[x+1][y] = '#';
    }else{
      s[x+1][y] = '.';
      ans = min(ans, 1 + cek(x,y+1));
      s[x+1][y] = '#';
      s[x+1][y+1] = '.';
      ans = min(ans, 1 + cek(x,y+1));
      s[x+1][y+1] = '#';
    }
  }else{
    ans = cek(x,y+1);
  }

  return ans;
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    s.resize(n);
    for (int i = 0; i < n; i++)
    {
      cin >> s[i];
    }
    
    int ans = cek(0,0);
    cout << ans << endl;
  }
  
}