#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  return (b==0 ? a : gcd(b,a%b));
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;
    int hcf = gcd(n,m);
    int lcm = (n/hcf)*m;
    cout << lcm << endl;
  }
  
}