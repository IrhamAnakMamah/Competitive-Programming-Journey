#include <bits/stdc++.h>
using namespace std;

string a[21];
int n,c,pb = 0;

void hapus(int x){
  for (int i = 0; i < c; i++)
  {
    a[x][i] = '0';
  }
}

void turun(){
  for (int i = pb-1; i >=0; i--)
  {
    for (int j = 0; j < c; j++)
    {
      if(a[i][j]=='1'){
        for (int k = i; k < n ; k++)
        {
          if(k==n-1){
            a[k][j] = a[i][j];
            a[i][j] = '0';
            break;
          }
          if(a[k+1][j]=='1'){
            a[k][j] = a[i][j];
            a[i][j] = '0';
            break;
          }

          if(a[k+1][j]=='0' && k+1 == n){
            a[k][j] = a[i][j];
            a[i][j] = '0';
            break;
          }
        }
        
      }
    }
    
  }
  
}

int main(){
  cin >> n >> c;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  while (true)
  {
    bool ok = 0;
    pb = 0;
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < c; j++)
      {
        if(a[i][j]=='1'){
          cnt++;
        }
      }
      if(cnt == c){
        ok = 1;
        pb = i;
        hapus(i);
      }
    }
  
    if(!ok) break;
    else turun();
  pb = 0;
  }
  
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << '\n';
  }
}