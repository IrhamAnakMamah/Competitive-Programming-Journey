#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,ans = 0;
  cin >> n;
  for (int i = 0; i <= 30; i++)
  {
    auto temp = (1<<i)&n;
    if(temp != 0){
      ans++;
    }
  }
  cout << ans << '\n';
}