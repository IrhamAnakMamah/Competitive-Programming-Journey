#include <bits/stdc++.h>
using namespace std;

int f(int n){//parameter
  if(n==0) return 0;//basis
  return n + f(n-1);//eksekusi, program inti
}

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    string n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i < 10; i++)
    {
      if(i==n[0]-'0'){
        ans = (10*(i-1))+f(n.length());
        break;
      }
    }
    cout << ans << "\n";
  }
  
}