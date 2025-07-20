#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      if(i>1 && (abs(a[i]-a[i-1])==1) && (a[i]!=i && a[i-1]!=i-1)){
        swap(a[i],a[i-1]);
      }
    }
    bool ok = 1;
    for (int i = 2; i <= n; i++)
    {
      if(a[i] < a[i-1]){
        ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
    
  }
  
}