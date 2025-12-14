#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if(i == 0){
      cout << -1 << endl;
    }else{
      int idx = -1;
      for (int k = i-1; k >= 0; k--)
      {
        if(a[k] > a[i]){
          idx = k+1;
          break;
        }
      }
      cout << idx << endl;
    }
  }
  
}