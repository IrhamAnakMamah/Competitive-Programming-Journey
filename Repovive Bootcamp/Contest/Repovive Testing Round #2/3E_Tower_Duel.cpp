#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    sort(a, a + n, greater<>());

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      if(a[i] == 0) continue;
      if(n == 1){
        ans ^= 1;
      }else{
        ans = (((a[i] > 2 ? a[i] - 1 : 0) + a[i]) % 2) ^ ans;
      }
    }
    cout << (ans == 1 ? "Sarah" : "Rayan") << endl;

  }
  
}