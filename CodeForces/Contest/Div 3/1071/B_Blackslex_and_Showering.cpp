#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      if(i > 0){
        sum += abs(a[i] - a[i-1]);
      }
    }
    
    int ans = sum;
    for (int i = 0; i < n; i++)
    {
      if(i == 0 || i == (n-1)){
        ans = min(ans, sum - abs((i == 0) ? a[i] - a[i+1] : a[i] - a[i-1]));
      }else{
        int temp = sum;
        temp -= abs(a[i] - a[i-1]);
        temp -= abs(a[i] - a[i+1]);
        temp += abs(a[i-1] - a[i+1]);
        ans = min(ans, temp);
      }
    }
    cout << ans << endl;
  }
  
}