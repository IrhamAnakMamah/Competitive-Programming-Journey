#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  multiset<pair<int,int>> mt1;
  int ans = n;
  while (m--)
  {
    int a,b;
    cin >> a >> b;
    if(mt1.empty()){
      ans -= (b - a + 1);
      mt1.insert({a,b});
    }else{
      auto it = mt1.upper_bound({a,0});
      if(it == mt1.begin()){
        cout << "Halo" << endl;
      }else{
        cout << it->second << endl;
      }
    }
    cout << ans << endl;
  }
  
}