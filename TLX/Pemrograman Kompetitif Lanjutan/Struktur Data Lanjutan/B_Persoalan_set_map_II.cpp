#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;

  set<int> s;

  for (int i = 1; i <= k+1; i++)
  {
    s.insert(i);
  }

  map<int,int> mp;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mp[a[i]]++;
    if(i < (k - 1)){
      if(mp[a[i]] == 1){
        s.erase(a[i]);
      }
    }else{
      if(mp[a[i]] == 1)s.erase(a[i]);
      cout << *s.begin() << endl;
      mp[a[i-(k-1)]]--;
      if(mp[a[i-(k-1)]] == 0) s.insert(a[i-(k-1)]);
    }
  }
  
}