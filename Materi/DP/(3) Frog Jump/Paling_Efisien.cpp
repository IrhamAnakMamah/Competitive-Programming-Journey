#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n ; i++) cin >> a[i];

    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++){
      int left = prev + abs(a[i]-a[i-1]);
      int right = INT_MAX;
      if(i>1) right = prev2 + abs(a[i]-a[i-2]);

      int cur = min(left,right);
      prev2 = prev;
      prev = cur;
    }
    cout << prev << "\n";
  }
  
}