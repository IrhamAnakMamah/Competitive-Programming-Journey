#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int k;
    cin >> k;
    int a[k];
    int sz = k-2;
    for (int i = 0; i < k; i++)
    {
      cin >> a[i];
    }
    sort(a,a+k);
    int l = 0;
    int r = k-1;
    while (l<r)
    {
      int sum = a[l]*a[r];
      if(sum==sz){
        break;
      }else if(sum>sz){
        r--;
      }else{
        l++;
      }
    }
    cout << a[l] << " " << a[r] << endl;
  }
  
}