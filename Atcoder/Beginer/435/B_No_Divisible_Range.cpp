#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= n-i; j++)
    {
      int sum = 0;
      for (int k = j; k < j+i; k++)
      {
        sum += a[k];
      }
      
      bool ok = 1;
      for (int k = j; k < j+i; k++)
      {
        if(sum % a[k] == 0){
          ok = 0;
        }
      }
      ans+=ok;
    }    
  }
  cout << ans << endl;
}