#include <bits/stdc++.h>
using namespace std;

int main(){
  multiset<int> cache;
  for (int i = 0; i < 31; i++)
  {
    cache.insert(1<<i);
  }
  int t;
  cin >> t;
  while (t--)
  {
    int a,b;
    cin >> a >> b;

    auto it = cache.upper_bound(a);
    if(*it - 1 < b){
      cout << -1 << endl;
    }else{
      int idx = distance(cache.begin(), it);
      bitset<32> temp(a);
      bitset<32> target(b);

      vector<int> ans;
      int cnt = 0;
      for (int i = 0; i < idx; i++)
      {
        if(temp[i] == 0){
          cnt += (1<<i);
          temp[i] = 1;
        } 
      }
      ans.push_back(cnt);
      if(temp == target){
        cout << 1 << endl;
        cout << ans.front() << endl;
      }else{
        cnt = 0;
        for (int i = 0; i < idx; i++)
        {
          if(target[i] == 0){
            cnt += (1<<i);
          }
        }
        ans.push_back(cnt);
        cout << ans.size() << endl;
        for(auto x : ans){
          cout << x << " ";
        }
        cout << endl;
      }
      
    }
  }
  
}