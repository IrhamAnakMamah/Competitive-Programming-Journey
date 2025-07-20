#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;

  string a[n][2];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
  }
  
  auto search = [&] (int l, int r, string s){

    while (l<r)
    {
      int mid = (l+r)/2;
      if(a[mid][0] == s){
        return a[mid][1];
      }else if(a[mid][0] > s){
        r = mid;
      }else{
        l = mid+1;
      }
    }
    if(l == r && a[r][0] == s){
      return a[r][1];
    }
  };

  for (int i = 0; i < q; i++)
  {
    string s;
    cin >> s;

    string ans = search(0,n-1,s);
    cout << ans << endl;
  }
  
}