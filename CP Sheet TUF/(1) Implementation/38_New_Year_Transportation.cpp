#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,t;
  cin >> n >> t;
  int a[n+2];
  for (int i = 1; i <= n-1; i++)
  {
    cin >> a[i];
  }
  int i = 1;
  while (i<=n)
  {
    if(i == t){
      cout << "YES" << endl;
      return 0;
    }else{
      i += a[i];
    }
  }
  
  cout << "NO" << endl;
}