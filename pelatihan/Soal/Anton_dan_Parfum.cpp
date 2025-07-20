#include <bits/stdc++.h>
using namespace std;

int n;
int a[100][2];

int f(int i, int uang){
  if(i==n){
    return 0;
  }

  // take and nottake
  int nottake = 0;
  int take = 0;
  if(uang>=a[i][0]){
    take = a[i][1] + f(i+1,uang-a[i][0]);
  }
  nottake = f(i+1,uang);

  return max(take,nottake);
}

int main(){
  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0] >> a[i][1];
  }
  
  int ans = f(0,m);
  cout << ans << endl;
}