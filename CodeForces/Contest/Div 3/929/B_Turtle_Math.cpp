#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while(t--){
    int n,sum = 0;
    cin >> n;
    vector<int > a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      sum+=a[i];
    }
    if(sum%3==0){
      cout << 0 << "\n";
    }else if(sum%3==2 || sum==1){
      cout << 1 << "\n";
    }else{
      bool ok = 0;
      for (int i = 0; i < n; i++)
      {
        if(a[i]%3==1){
          ok = 1;
          break;
        }
      }
      (ok) ? cout << 1 << "\n" : cout << 2 << "\n";
    }
  }
}