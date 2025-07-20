#include <bits/stdc++.h>
using namespace std;

int gcd (int a,int b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int l,r;
    cin >> l >> r;
    int ans = (r-(r/2))-(l-(l/2));
    if(l&1)ans++;
    cout << ans/2 << endl;
    
  }
  
}