#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  char s[n][m];
  char key[3] = "BW";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> s[i][j];
    }
    
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(s[i][j]=='.'){
        cout << key[(i+j)%2];
      }else{
        cout << s[i][j];
      } 
    }
    cout << "\n";
  }
  
}