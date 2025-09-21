#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  string s[n];
  string t[m];

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  for (int i = 0; i < m; i++)
  {
    cin >> t[i];
  }
  
  int x = -1;
  int y = -1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(s[i][j] == t[0][0]){
        bool ok = 1;
        for (int k = 0; k < m; k++)
        {
          for (int l = 0; l < m; l++)
          {
            if(i+k >= n || j+k >= n){
              ok = 0;
              break;
            }
            if(s[i+k][j+l] != t[k][l]){
              ok = 0; 
            }
          }
          
        }
        if(ok){
          x = i;
          y = j;
        } 
      }
    }
    
  }
  cout << x+1 << " " << y+1 << endl;
}