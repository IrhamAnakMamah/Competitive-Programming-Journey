#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;

  int sum = 0;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum+=a[i];
  }
  int patokan = sum/m;
  int mx = 0;
  int temp = a[0];
  for (int i = 1; i < n; i++)
  {
    if(temp + a[i] <= patokan+1){
      temp+=a[i];
    }else{
      mx = max(mx, temp);
      temp = a[i];
    }
  }
  mx = max(mx, temp);
  cout << mx << endl;
}