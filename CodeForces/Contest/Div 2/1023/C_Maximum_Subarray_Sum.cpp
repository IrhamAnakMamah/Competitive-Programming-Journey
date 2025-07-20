#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const ll INF = -1e13;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,k;
    bool ok = 1;
    cin >> n >> k;
    string s;
    cin >> s;
    ll a[n];

    int index = -1;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(s[i]=='0'){
        index = i;
        a[i] = INF;
      }
    }

    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
      sum = max(sum + a[i], a[i]);
      mx = max(mx,sum);
    }
    
    if(mx>k || (mx!=k && index==-1)){
      ok = 0;
    }else{
      sum = 0;
      mx = 0;
      ll count1 = 0;
      ll count2 = 0;
      for (int i = index+1; i < n; i++)
      {
        sum+=a[i];
        mx = max(sum,mx);
      }
      count1 =mx;
      sum = 0;
      mx = 0;
      for (int i = index-1; i >= 0; i--)
      {
        sum+=a[i];
        mx = max(sum,mx);
      }
      count2 = mx;
      a[index] = k - count1 - count2;
    }
    
    if(!ok){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
      for (int i = 0; i < n; i++)
      {
        cout << a[i] << " ";
      }
      cout << endl;
    }
  }
  
}