#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;

  int nest[n+1];
  int burung[n];
  for (int i = 1; i <= n; i++)
  {
    nest[i] = 1;
    burung[i] = i;
  }

  int ans = 0;
  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if(x == 1){
      int y,z;
      cin >> y >> z;
      if(nest[burung[y]] == 2){
        ans--;
      }
      nest[burung[y]]--;
      burung[y] = z;
      if(nest[burung[y]] == 1){
        ans++;
      }
      nest[burung[y]]++;
    }else{
      cout << ans << endl;
    }
  }
  
}