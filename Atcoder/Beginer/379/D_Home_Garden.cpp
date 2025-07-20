#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int q;
  cin >> q;
  queue<int> pot;
  vector<ll> h(q+1);
  h[0] = 0;
  int ans = 0;
  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if(x==1){
      h[i+1] = h[i];
      pot.push(i);
    }else if(x==2){
      int y;
      cin >> y;
      h[i+1]=h[i]+y;
    }else{
      int y;
      cin >> y;
      h[i+1] = h[i];
      ans = 0;
      while (!pot.empty())
      {
        if(h[i+1] - h[pot.front()]>=y){
          ans++;
          pot.pop();
        }else{
          break;
        }
      }
      cout << ans << endl;
    }
  }
  
}