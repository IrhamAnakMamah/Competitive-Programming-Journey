#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);
  int x,y,m;
  cin >> x >> y >> m;

  int temp = 0;
  int ans = 0;
  int i = (m/x)+1;
  int j = 0;
  
  while (i>0)
  {
    temp = i * x;
    temp += j * y;
    if(temp <= m){
      ans = max(ans,temp);
      j++;
    }else{
      i--;
    }
  }
  cout << ans << endl;
}