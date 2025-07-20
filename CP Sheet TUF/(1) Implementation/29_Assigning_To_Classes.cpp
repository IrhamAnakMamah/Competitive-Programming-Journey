#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n*2];
    for (int i = 0; i < n*2; i++){
      cin >> a[i];
    }
    sort(a,a+(n*2));
    cout << abs(a[n] - a[n-1]) << "\n";
  }
  
}