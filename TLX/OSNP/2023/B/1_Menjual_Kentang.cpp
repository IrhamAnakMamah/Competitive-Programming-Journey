#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
  int n,m;
  cin >> n >> m;

  ll sum1 = 0;
  ll sum2 = 0;

  ll a[n];
  ll b[m];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum1+=a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
    sum2+=b[i];
  }
  
  sort(b,b+m, greater<int>());

  vector<ll> pref(m+1, 0);
  for (int i = 1; i <= m; i++)
  {
    pref[i] = pref[i-1] + b[i-1];
  }
  
  ll ans = INT_MAX;
  ll temp = 0;
  
  if((double)sum1/n > (double)sum2/m){
    cout << 0 << endl;
  }else{
    int index = -1;
    for (int i = 1; i < m; i++)
    {
      double x,y;
      temp = pref[i];
      x = sum1+temp;
      x = (double)(x)/(n+i);
      y = sum2 - temp;
      y = (double)(y)/(m-i);
      if(x>y){
        index = i - 1;
        break;
      }
    }

    if(index!=-1){
      for (int i = index; i < m; i++)
      {
        if(b[i] == b[index]){
          index = i;
        }
      }
      ans = pref[index+1];
    }else{
      ans = -1;
    }
    cout << ans << endl;
  }
  
  
}