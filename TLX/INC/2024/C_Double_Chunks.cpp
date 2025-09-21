#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  set<int> s;
  map<int,int> mp;

  int temp = a[1] + a[0];
  s.insert(temp);
  mp[temp]++;
  bool ok = 1;

  for (int i = 1; i < n-1; i++)
  {
    temp = a[i] + a[i+1];
    if(a[i] + a[i-1] != temp || !ok){
      s.insert(temp);
      mp[temp]++;
      ok = 1;
    }else{
      ok = 0;
    }
  }
  
  int mx = 0;
  for(auto x : s){
    mx = max(mp[x], mx);
  }
  cout << mx << endl;
}