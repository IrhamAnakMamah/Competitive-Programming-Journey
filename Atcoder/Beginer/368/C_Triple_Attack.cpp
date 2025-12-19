#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  ll t = 0;
  for (int i = 0; i < n; i++)
  {
    ll temp = a[i]/5;
    t += (temp * 3);
    a[i] = a[i] % 5;
    while (a[i] > 0)
    {
      if((t + 1) % 3 == 0){
        a[i] -= 3;
      }else{
        a[i]--;
      }
      t++;
    }
  }
  cout << t << endl;
}