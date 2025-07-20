#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n;
  cin >> n;
  ll a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  if(n==1){
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;
  }else{
    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;
    cout << 1 << " " << n << endl;
    cout << 0 << " ";
    for (int i = 1; i < n; i++)
    {
      cout << n*a[i]*-1 << " ";
    }
    cout << endl;
    cout << 2 << " " << n << endl;
    for (int i = 1; i < n; i++)
    {
      cout << (n-1)*a[i] << " ";
    }
    cout << endl;
  }
}