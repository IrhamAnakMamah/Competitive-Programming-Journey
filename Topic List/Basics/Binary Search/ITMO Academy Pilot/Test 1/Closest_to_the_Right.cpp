#include <bits/stdc++.h>
using namespace std;
  
int n,q;
const int MAXN = 1e5+5;
int a[MAXN];

int search (int x){
  int l = -1;
  int r = n;
  while (l+1<r)
  {
    int sum = (l+r)/2;
    if(a[sum]>=x) r = sum;
    else l = sum;
  }
  return r+1;
}

int main(){
  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  while (q--)
  {
    int x;
    cin >> x;
    int ans = search(x);
    cout << ans << "\n";
  }
  
}