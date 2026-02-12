#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2e5+7;
int n;
ll a[MAXN];
int l[MAXN];
int r[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    while(!s.empty() && a[s.top()] >= a[i]){
      s.pop();
    }
    if(s.empty()){
      l[i] = -1;
    }else{
      l[i] = s.top();
    }
    s.push(i);
  }

  while(!s.empty()) s.pop();

  for (int i = n - 1; i >= 0; i--)
  {
    while(!s.empty() && a[s.top()] > a[i]){
      s.pop();
    }
    if(s.empty()){
      r[i] = n;
    }else{
      r[i] = s.top();
    }
    s.push(i);
  }
  
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll left_dist = i - l[i];
    ll right_dist = r[i] - i;
    ans += left_dist * right_dist * a[i];
  }
  cout << ans << endl;
}