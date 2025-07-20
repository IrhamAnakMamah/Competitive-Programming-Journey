#include <bits/stdc++.h>
using namespace std;

int n,k;
const int MAXN = 1e4+1;
int a[MAXN];

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  double l = 0;
  double r = 1e7;

  for (int i = 0; i < 100; i++)
  {
    double m = (l+r)/2;
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum+=(int)(a[j]/m);
    }
    if(sum>=k){
      l = m;
    }else{
      r = m;
    }
  }
  cout << setprecision(14) << l << "\n";
}