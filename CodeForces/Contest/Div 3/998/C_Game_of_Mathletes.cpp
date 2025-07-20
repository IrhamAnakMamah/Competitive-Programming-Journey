#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    int i = 0;
    int j = n-1;
    while (i<j)
    {
      int sum = a[i]+a[j];
      if(sum==k){
        ans++;
        i++;
        j--;
      }else if(sum<k){
        i++;
      }else{
        j--;
      }
    }
    
    cout << ans << endl;
  }
  
}