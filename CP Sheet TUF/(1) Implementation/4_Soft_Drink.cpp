#include <bits/stdc++.h>
using namespace std;

int main (){
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int temp1 = (k*l)/nl;
  int temp2 = p/np;
  int minim = min(temp1,min(temp2,c*d));
  cout << minim/n << "\n";
}