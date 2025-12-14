#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int n;
int a[MAXN];

int main(){
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int mx = 0;
  int cnt = 1;
  int sekarang = a[0];

  for (int i = 1; i < n; i++)
  {
    if(i&1){
      cnt++;
    }else{
      int temp = abs(a[i] - sekarang);
      if(temp == 0 || temp == 2){
        cnt++;
      }else{
        mx = max(cnt, mx);
        cnt = 2;
      }
      sekarang = a[i];
    }
  }
  mx = max(cnt, mx);
  cout << mx << endl;
  
}