#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  int ans = 0;

  auto search = [&] (int l, int r, int x){
    while (l<r)
    {
      int mid = (l+r)/2;
      if(a[mid] == x){
        return true;
      }else if(a[mid] > x){
        r = mid - 1;
      }else{
        l = mid+1;
      }
    }
    if(l == r && a[l] == x){
      return true;
    }else{
      return false;
    }
  };

  for (int i = 0; i < n; i++)
  {
    int nunduk = a[i] + d;
    int index = -1;
    int l = i;
    int r = n-1;
    ans+=search(l,r,nunduk);
  }
  cout << ans << endl;
}