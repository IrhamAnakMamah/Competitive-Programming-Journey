#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    bool ok = 1;
    for (int i = 0; i < n-1; i++)
    {
      int temp = abs(a[i]-a[i+1]);
      if(temp != 5 && temp!=7){
        ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  
}