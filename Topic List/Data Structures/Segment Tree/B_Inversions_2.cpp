#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

const int MAXN = 1e5+7;
ll n,m;
ll t[4*MAXN];

void build(int v, int tl, int tr){
  if(tl == tr){
    t[v] = 1; 
  }else{
    int tm = (tl+tr)/2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
  }
}

ll calc(int v, int tl, int tr, int k){
  if(tl == tr){
    // cout << tl << endl;
    return tl;
  }else{
    int tm = (tl+tr)/2;
    if(k <= t[tm*2]){
      calc(v*2, tl, tm, k);
    }else{
      calc(v*2+1, tm+1, tr, k-t[tm*2]);
    }
  }
}

void update(int v, int tl, int tr, int pos){
  if(tl == tr){
    // cout << v << endl;
    t[v] = 0;
  }else{
    int tm = (tl+tr)/2;
    if(pos <= tm){
      update(v*2, tl, tm, pos);
    }else{
      update(v*2+1, tm+1, tr, pos);
    }
    t[v] = t[v*2] + t[v*2+1];
  }
}

int main(){
  for (int i = 0; i < 4*MAXN; i++)
  {
    t[i] = 0;
  }
  
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  build(1,0,n-1);
  reverse(a.begin(), a.end());
  vector<int> ans;
  for (int i = 0; i < n; i++)
  {
    int pos = calc(1,0,n-1,a[i]+1);
    cout << pos << endl;
    ans.push_back(pos);
    update(1,0,n-1,pos);
  }
  reverse(ans.begin(), ans.end());
  for(auto xx : ans){
    cout << xx << " ";
  }
  cout << endl;
}