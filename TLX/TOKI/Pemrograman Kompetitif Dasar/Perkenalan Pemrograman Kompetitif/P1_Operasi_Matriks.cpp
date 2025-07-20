#include <bits/stdc++.h>
using namespace std;

int a[101][101];
int temp[101][101];
int n,m,x;

void fix(){
  for(int i = 0;i<n;i++){
    for (int j = 0; j < m; j++)
    {
      a[i][j] = temp[i][j];
    }
  }
}

void rotate(){
  int k = 0, l = 0;
  for (int i = 0; i < m; i++)
  {
    l=0;
    for (int j = n-1; j >= 0; j--)
    {
      temp[k][l] = a[j][i];
      l++; 
    }
    k++;
  }
  int wow = 0;
  wow = n;
  n = m;
  m = wow;
  fix();
}

int main (){
  cin >> n >> m >> x;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < x; i++)
  {
    string s; 
    cin >> s;
    if(s=="_"){
      int k = 0, l = 0;
      for (int i = n-1; i >=0; i--)
      {
        l=0;
        for (int j = 0; j < m; j++)
        {
          temp[k][l] = a[i][j];
          l++; 
        }
        k++;
      }
      fix();
    }else if(s=="|"){
      int k = 0, l = 0;
      for (int i = 0; i < n; i++)
      {
        l=0;
        for (int j = m-1; j >= 0; j--)
        {
          temp[k][l] = a[i][j];
          l++; 
        }
        k++;
      }
      fix();
    }else if(s=="90"){
      rotate();
    }else if(s=="180"){
      rotate();
      rotate();
    }else if(s=="270"){
      rotate();
      rotate();
      rotate();
    }    
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }
  
}