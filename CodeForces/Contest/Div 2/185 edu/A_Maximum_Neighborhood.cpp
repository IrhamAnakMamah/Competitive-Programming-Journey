#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n][n];
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        a[i][j] = cnt;
        cnt++;
      }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int temp = 0;
        if(i > 0){
          temp += a[i-1][j];
        }
        if(j > 0){
          temp += a[i][j-1];
        }
        if(i < n-1){
          temp += a[i+1][j];
        }
        if(j < n-1){
          temp += a[i][j+1];
        }
        temp += a[i][j];
        ans = max(ans, temp);
      }
      
    }
    cout << ans << endl;
    
  }
}