#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    int a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    
    int sum = a[0] + a[1] + a[2];
    int ans = n/sum;
    if(n!=(ans*sum)){
      int temp = n - (ans*sum);
      ans*=3;
      for (int i = 0; i < n; i++)
      {
        temp-=a[i];
        ans++;
        if(temp<=0){
          break;
        }
      }
    }else{
      ans*=3;
    }
    cout << ans << endl;
  }
  
}