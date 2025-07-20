#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int main(){
  int n,k;
  int ans = 0;
  cin >> n >> k;
  int a[n];
  
  vector<int>banyak(MAXN,0);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    banyak[a[i]-1]++;
  }
  
  sort(banyak.begin(),banyak.end(), greater<>());

  for (int i = 0; i < k; i++)
  {
    if(banyak[i]>0){
      ans+=banyak[i]  -1;
    }
  }
  
  cout << ans << endl;
}