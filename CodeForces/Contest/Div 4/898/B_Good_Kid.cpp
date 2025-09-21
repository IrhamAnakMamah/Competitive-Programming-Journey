#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int mn = *min_element(a.begin(), a.end());

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      if(mn == a[i] && mn != -1){
        ans = ans * (a[i] + 1);
        mn = -1;
      }else{
        ans *= a[i];
      }
    }
    cout << ans << endl;
  }
  
}