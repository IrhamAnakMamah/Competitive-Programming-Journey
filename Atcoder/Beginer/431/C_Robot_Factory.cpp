#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,k;
  cin >> n >> m >> k;

  int a[n];
  int b[m];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
  }

  sort(a,a+n);
  sort(b,b+m);

  int cnt = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < m)
  {
    if(a[i] <= b[j]){
      cnt++;
      i++;
      j++;
    }else{
      j++;
    }
  }
  cout << (cnt >= k ? "Yes" : "No") << endl;
  
}