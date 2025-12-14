#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  map<int,int> mp;

  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int temp = 0;
    int a;
    cin >> a;
    if(a - d > 0){
      temp = mp[a-d];
    }
    temp = max(temp, mp[a+d]);
  }
  cout << ans << endl;
}