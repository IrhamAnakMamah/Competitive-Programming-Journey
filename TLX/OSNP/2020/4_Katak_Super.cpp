#include <bits/stdc++.h>
using namespace std;

int n;
int f(int i, int a[]){
  if(i==n-1){
    return 0;
  }

  int take = 0;
  int nottake = 0;
  if(i==0){
    take = a[i];
    nottake = a[i];
  }

  take += pow(a[i+1]-a[i],2) + f(i+1,a);
  if(i+2<n){
    nottake += (3*pow(a[i+2]-a[i],2)) + f(i+2,a);
  }
  
  return min(take,nottake);
}

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int ans = f(0,a);
    cout << ans << endl;
  }
  
}