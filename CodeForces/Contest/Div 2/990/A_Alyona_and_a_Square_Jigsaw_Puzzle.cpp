#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int sum = 0;
    // rumus = temp + ((i*4)+4);
    // i = i +2;
    int rumus = 1;
    int k = 1;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      sum+=a;
      if(sum>=rumus){
        while (sum>rumus)
        {
          k+=2;
          rumus = pow(k,2);
        }
        
        if(sum==rumus){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  
}