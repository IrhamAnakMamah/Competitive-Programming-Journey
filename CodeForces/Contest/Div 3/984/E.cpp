#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,q;
  cin >> n >> k >> q;
  int a[n][k];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      int x;
      cin >> x;
      if(i==0){
        a[i][j]=x;
      }else{
        a[i][j] = x|a[i-1][j];
      }
    }
  }
  
  for (int i = 0; i < q; i++)
  {
    int l = 0, r = n-1;
    int z;
    cin >> z;
    for (int j = 0; j < z; j++)
    {
      int x,y;
      char c;
      cin >> x >> c >> y;
      
    } 
  
}
