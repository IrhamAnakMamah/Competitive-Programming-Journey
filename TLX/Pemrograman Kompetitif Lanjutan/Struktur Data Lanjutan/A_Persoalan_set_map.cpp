#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  set<int> s;
  map<int,int> mp;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    mp[a[i]]++;
    if(i < (k-1)){
      s.insert(a[i]);
    }else{
      s.insert(a[i]);
      cout << s.size() << endl;
      mp[a[i-(k-1)]]--;
      if(mp[a[i-(k-1)]] == 0){
        s.erase(a[i-(k-1)]);
      }
    }
  }
}