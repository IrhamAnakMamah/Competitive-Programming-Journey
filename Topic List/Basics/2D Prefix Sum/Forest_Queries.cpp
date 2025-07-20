#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  char a[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
    
  }

  vector<vector<int>> pref(n+1, vector<int>(n+1,0));

  for (int i = 1; i <= n; i++)
  {
    int temp = 0;
    if(a[0][i-1] == '*') temp++;
    pref[1][i] = pref[1][i-1] + temp;
  }
  
  for (int i = 2; i <= n; i++)
  {
    int temp = 0;
    if(a[i-1][0] == '*') temp++;
    pref[i][1] = pref[i-1][1] + temp;
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 2; j <= n; j++)
    {
      int temp = 0;
      if(a[i-1][j-1]=='*') temp++;
      pref[i][j] = pref[i][j-1] + (pref[i-1][j]-pref[i-1][j-1]) + temp; 
    }
    
  }
  
  for (int i = 0; i < q; i++)
  {
    int x1,x2,y1,y2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << pref[y2][x2] - pref[y1-1][x2] - pref[y2][x1-1] + pref[y1-1][x1-1] << endl;
  }
}
