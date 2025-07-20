#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int prev = a[0];
  int prev2 = 0;
  for (int i = 1; i < n; i++){
    int pick = a[i];
    if(i>1) pick+=prev2;

    int notpick = prev;
    int cur = max(pick,notpick);

    prev2 = prev;
    prev = cur;
  }
  cout << prev << "\n";
}