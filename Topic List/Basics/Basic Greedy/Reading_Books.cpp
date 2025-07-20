#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  int n;
  cin >> n;

  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a,a+n);
  
  ll sum = 0;
  for (int i = 0; i < n-1; i++)
  {
    sum+=a[i];
  }

  if(sum<a[n-1]){
    sum+=(a[n-1]-sum) + a[n-1];
  }else{
    sum+=a[n-1];
  }
  
  cout << sum << endl;

}