#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,k,x;
    cin >> n >> k >>x;
    ll mx = 0;
    ll mn = 0;
    for (int i = 1; i <= k; i++)
    {
      mn+=i;
    }
    for (int i = n;i>n-k;i--)
    {
      mx+=i;
    }
    
    if(x>=mn && x<=mx){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  
}