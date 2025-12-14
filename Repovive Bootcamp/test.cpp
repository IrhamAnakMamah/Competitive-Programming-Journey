#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(tuple<ll, ll, int> &a, tuple<ll, ll, int> &b){
  auto [x1,y1,z1] = a;
  auto [x2,y2,z2] = b;

  if(x1 == x2 && y1 == y2){
    return z1 < z2;
  }else if(x1 == x2){
    return y1 < y2;
  }else{
    return x1 < x2;
  }
}

int main(){
  int n;
  cin >> n;

  vector<tuple<ll,ll,int>> v(n);
  ll a[n];
  ll b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    v[i] = {a[i], b[i], i};
  }
  
  sort(v.begin(), v.end(), comp);
  for (int i = 0; i < n; i++)
  {
    auto [x,y,z] = v[i];
    cout << "x : " << x << ", y : " << y << ", z : " << z << endl;
  }
  
}