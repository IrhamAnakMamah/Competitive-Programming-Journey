#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,l,r;
    cin >> n >> l >> r;
    int a[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    int idx = 0;
    int temp[n];
    for (int i = 0; i < l-1; i++,idx++)
    {
      temp[idx] = a[i];
    }
    sort(a+l-1,a+r);
    sort(temp+l-1,temp+r);

    int idx2 = 0;
    for (int i = l-1; i < r; i++)
    {
      if(a[i]>temp[idx2] && idx2<idx){
        ans+=temp[idx2];
        idx2++;
      }else ans+=a[i];
    }
    
    idx = 0;
    for (int i = r; i < n; i++,idx++)
    {
      temp[idx] = a[i];
    }
    sort(a+l-1,a+r);
    sort(temp+l-1,temp+r);

    int idx2 = 0;
    for (int i = l-1; i < r; i++)
    {
      if(a[i]>temp[idx2] && idx2<idx){
        ans+=temp[idx2];
        idx2++;
      }
    }
  }
  
}