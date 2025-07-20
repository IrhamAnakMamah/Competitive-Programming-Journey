#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  int a[n];
  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> s;
  for (int i = 0; i < q; i++)
  {
    int x;
    cin >> x;
    if(s[x-1]=='R'){
      s[x-1]=='L';
    }else{
      s[x-1]=='R';
    }
  }
  

}