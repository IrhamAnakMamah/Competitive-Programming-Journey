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
    ll a[n];
    ll mx1 = 0;
    ll mx2 = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    ll mx = 0;
    for (int i = 1; i < n; i+=2)
    {
      mx = max(mx,a[i]-a[i-1]);
    }

    ll maxim = 0;
    for (int i = 0; i < n; i+=2)
    {
      ll temp = 0;
      for (int j = 1; j < n; j+=2)
      {
        if(j-1==i){
          j++;
          if(j==n){
            break;
          }
        }
        temp = max(temp,a[j]-a[j-1]);
      }
      if(i==0){
        maxim = temp;
      }else{
        maxim = min(maxim,temp);
      }
    }
    maxim = min(maxim,mx);
    
    if(n==1){
      cout << 1 << '\n';
    }else if (n&1){
      cout << maxim << "\n";
    }else{
      cout << mx << '\n';
    }
  }
  
}