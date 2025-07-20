#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, minim,ans = 0;
  cin >> n;
  int a[n];
  for(int i = 0;i<n;i++){
    cin >> a[i];
  }

  int j = 1;

  while (true)
  {
    bool ok = 1;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
      if(a[i]>=a[i-1]){
        continue;
      }else{
        k = i;
        ok = 0;
        break;
      }
    }
    if(!ok){
      for (int i = k; i > 0; i--)
      {
        if(a[i]<a[i-1]){
          ans++;
          swap(a[i],a[i-1]);
        }else{
          break;
        }
      }
    }else{
      break;
    }
    j++;
  }
  
  cout << ans << '\n';
}