#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,mx = INT_MIN;
    bool ok = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      mx = max(mx,a[i]);
      ok = ((i>=1 && a[i]!=a[i-1])||(ok));
    }

    if(ok){
      cout << "YES" << endl;
      for (int i = 0; i < n; i++)
      {
        cout << (a[i]==mx ? 2 : 1) << " ";
      }
      cout << endl;
    }else{
      cout << "NO" << endl;
    }

  }
  
}