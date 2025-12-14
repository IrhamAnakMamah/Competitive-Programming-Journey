#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;

  if(a != b){
    cout << "NO" << endl;
    return 0;
  }

  ll temp = n;
  temp = temp | (temp * 2);
  temp = temp & (temp * 2);

  if(temp == (2 * n)){
    cout << "YES" << endl;
    return 0;
  }

  temp = n;
  temp = temp & (temp * 2);
  temp = temp | (temp * 2);

  if(temp == (2 * n)){
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}