#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main (){
  ll n, target;
  cin >> n >> target;
  ll b[n];
  vector<pair<ll,ll>> a;

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  sort(b,b+n);

  for (int i = 0; i < n; i++)
  {
    a.push_back(make_pair(abs(b[i]-target),b[i]));
  }
  sort(a.begin(), a.end());
  int temp = a[0].first;
  for (int i = 0; i < n; i++)
  {
    if(a[i].first == temp)
    cout << setw(5) << setfill('0') << a[i].second << "\n";
  }
  
  return 0;
}