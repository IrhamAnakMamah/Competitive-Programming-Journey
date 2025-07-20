#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  int a[n];
  int b[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i]; 
  }
  
  for (int i = 1; i <= d; i++)
  {
    int mx = 0;
    for (int j = 0; j < n; j++)
    {
      mx = max(mx,a[j]*(b[j]+i));
    }
    cout << mx << endl;
  }
  
}