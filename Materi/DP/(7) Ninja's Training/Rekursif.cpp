#include <bits/stdc++.h>
using namespace std;

int f(int a[][3], int n, int last){
  if(n==0){
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
      if(i!=last){
        maxi = max(maxi,a[0][i]);
      }
    }
    return maxi;
  }
  int maxi = 0;
  int point = 0;
  for (int i = 0; i < 3; i++)
  {
    if(i!=last){
      point = a[n][i] + f(a,n-1,i);
    }
    maxi = max(maxi,point);
  }
  return maxi;
}

int main (){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cin >> a[i][j];
      }
    }
    int ans = f(a,n-1,NULL);
    cout << ans << "\n";
  }
}