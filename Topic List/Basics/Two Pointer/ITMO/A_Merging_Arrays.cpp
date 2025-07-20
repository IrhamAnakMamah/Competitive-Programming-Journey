#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  int a[n];
  int b[m];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  
  int i = 0;
  int j = 0;
  while (i!=n || j!=m)
  {
    if(i<n && j<m){
      if(a[i]<b[j]){
        cout << a[i] << " ";
        i++;
      }else{
        cout << b[j] << " ";
        j++;
      }
    }else if(j==m){
      cout << a[i] << " ";
      i++;
    }else if(i==n){
      cout << b[j] << " ";
      j++;
    }
  }
  cout << endl;
  
}