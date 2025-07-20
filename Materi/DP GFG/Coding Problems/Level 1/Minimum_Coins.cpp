#include <bits/stdc++.h>
using namespace std;

int f(int a[], int n, int k,int count){
  if(k==0){
    return count;
  }if(k<0) return 0;
  if(n<0) return 0;

  int take = f(a,n,k-a[n],count + 1);
  int notake = f(a,n-1,k,count);
  if(take<=0)take = INT_MAX;
  if(notake<=0)notake = INT_MAX;
  return min(take,notake);
}

int main (){
  int n,k;
  cin >> n;
  int coin[n];
  for (int i = 0; i < n; i++){
    cin >> coin[i];
  }
  cin >> k;
  sort(coin,coin+n);
  int ans = f(coin,n-1,k,0);
  if(ans == INT_MAX) ans = -1;
  cout << ans << "\n";
}