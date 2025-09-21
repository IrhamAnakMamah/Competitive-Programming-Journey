#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  map<int,int> cache;
  int start = 0;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if(cache.find(a[i]) == cache.end()){
      cache[a[i]] = i;
    }else{
      if(cache[a[i]] >= start){
        start = cache[a[i]] + 1;
      }
      cache[a[i]] = i;
    }
    ans = max(ans, i - start + 1);
  }
  cout << ans << endl;
  
}