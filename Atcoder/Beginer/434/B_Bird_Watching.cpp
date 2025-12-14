#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n,k;
  cin >> n >> k;

  double w[k+1];
  double cnt[k+1];
  for (int i = 0; i < n; i++)
  {
    int a;
    double b;
    cin >> a >> b;
    a--;
    w[a] += b;
    cnt[a]++;
  }
  
  for (int i = 0; i < k; i++)
  {
    cout << fixed << setprecision(10) << (double)(w[i]/cnt[i]) << endl;
  }
  
}