#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i] >> b[i];
    }

    int ans = 0;
    int time = 0;
    bool side = 0;
    for (int i = 0; i < n; i++)
    {
      int temp = a[i] - time;
      if(temp > 2){
        if(b[i] == side && temp % 2 == 0){
          ans += temp;
          time = a[i];
        }else if(b[i] != side && temp % 2 == 1){
          ans += temp;
          time = a[i];
          side = b[i];
        }else{
          ans += temp-1;
          time = a[i];
          side = b[i];
        }
      }else{
        if(b[i] == side && temp == 2){
          ans += 2;
        }else if(b[i] != side){
          ans++;
          side = b[i];
        }
        time = a[i];
      }
    }
    cout << ans + (m - time) << endl;
  }
  
}