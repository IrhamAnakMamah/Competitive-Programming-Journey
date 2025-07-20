#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ll b[m];
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }
  sort(a,a+n);
  sort(b,b+m);
  int ans = 0;
  int i = 0,j = 0;
  while (i<n && j<m)
  {
    if(abs(a[i]-b[j])<=k){
      i++;
      j++;
      ans++;
    }else if(a[i]-b[j]>k){
      j++;
    }else{
      i++;
    }
  }
  
  cout << ans << "\n";
}