#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
  int n;
  cin >> n;

  int volume = 0;
  bool isOn = 0;
  while (n--)
  {
    int a;
    cin >> a;
    if(a == 1){
      volume++;
    }else if(a == 2){
      if(volume > 0){
        volume--;
      }
    }else{
      isOn^=1;
    }

    if(isOn && (volume >= 3)){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
  

  return 0;
}