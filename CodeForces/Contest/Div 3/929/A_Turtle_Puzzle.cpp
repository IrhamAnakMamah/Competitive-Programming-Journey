#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while(t--){
    int n,a,ans=0;
    cin >> n;
    while (n--){
      cin >> a;
      ans+=abs(a);
    }
    cout << ans << "\n";
  }
}