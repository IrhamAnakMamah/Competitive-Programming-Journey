#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    ll a;
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
      mx = max(mx,a);
    }
    
    vector<ll> ans;
    for (int i = 0; i < m; i++)
    {
      char c;
      int l,r;
      cin >> c >> l >> r;
      if(c=='+'){
        if(mx>=l && mx<=r){
          mx++;
        }
        ans.push_back(mx);
      }else{
        if(mx>=l && mx<=r){
          mx--;
        }
        ans.push_back(mx);
      }
    }
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }
  
}