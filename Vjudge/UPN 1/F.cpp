#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
  int n;
  cin >> n;
  ll a, b, maxim = 0,temp = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    maxim = max(maxim,b-a);
    temp+=a;
  }
  
  cout << maxim + temp << "\n";
  return 0;
}