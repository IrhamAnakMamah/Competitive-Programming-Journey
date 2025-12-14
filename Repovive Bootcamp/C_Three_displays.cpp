#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3001;
using ll = long long;
int n;
ll s[MAXN];
ll c[MAXN];

int main(){
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> c[i];
  }
  
  ll ans = INT_MAX;
  for (int i = 1; i < n; i++)
  {
    ll temp1 = INT_MAX;
    ll temp2 = INT_MAX;
    for (int j = 0; j < i; j++)
    {
      if(s[j] < s[i]){
        temp1 = min(temp1, c[j]);
      }
    }
    
    for (int j = i+1; j < n; j++)
    {
      if(s[j] > s[i]){
        temp2 = min(temp2, c[j]);
      }
    }
    
    if(temp1 != INT_MAX && temp2 != INT_MAX){
      ans = min(ans, temp1 + temp2 + c[i]);
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << endl;
}