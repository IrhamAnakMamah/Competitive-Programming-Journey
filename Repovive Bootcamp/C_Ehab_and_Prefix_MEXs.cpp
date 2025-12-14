#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  int b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  vector<int> cnt(n+1, 0);
  for (int i = 0; i < n; i++)
  {
    cnt[a[i]]++;
  }
  
  bool ok = 1;
  int var1 = 0; // yang bakal ngisi posisi disticnt value
  int var2 = 0; // yang bakal gerak terus 
  for (int i = 0; i < n; i++)
  {
    if(i == 0){
      if(a[i] == 0){
        var1 = 0;
        for (int i = 1; i <= n; i++)
        {
          if(cnt[i] == 0){
            var2 = i;
            break;
          }
        }
        b[i] = var2;
        for (int i = var2 + 1; i <= n; i++)
        {
          if(cnt[i] == 0){
            var2 = i;
            break;
          }
        }
      }else{
        var1 = a[i];
        b[i] = 0;
        for (int i = 1; i <= n; i++)
        {
          if(cnt[i] == 0){
            var2 = i;
            break;
          }
        }
      }
    }else{
      if(a[i-1] == a[i]){
        b[i] = var2;
        for (int i = var2 + 1; i <= n; i++)
        { 
          if(cnt[i] == 0){
            var2 = i;
            break;
          }
        }
      }else{
        b[i] = var1;
        var1 = a[i];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << b[i] << " ";
  }
  cout << endl;
  
}