#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main(){
  ll n,target;
  cin >> n >> target;

  ll a[n];
  ll sum = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum+=a[i];
  }
  
  int i = 0;
  int j = n-1;

  while (i<j && sum > target)
  {
    if(a[i] > a[j]){
      sum -= a[i];
      i++;
    }else{
      sum -= a[j];
      j--;
    }
  }
  
  if(j-i == 0 && a[j]>target){
    cout << 0 << endl;
  }else{
    cout << j-i+1 << endl;
  }
}