#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,target,count = 0;
    cin >> n >> m >> target;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for (int i = 0; i < m; i++){
      cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+m);

  }
  
}