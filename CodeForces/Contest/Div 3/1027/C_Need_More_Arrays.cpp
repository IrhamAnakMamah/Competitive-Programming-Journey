#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    
    int ans = 1;

    int a;
    cin >> a;
    int temp = a;

    for (int i = 1; i < n; i++)
    {
      cin >> a;
      if(a>temp+1){
        ans++;
        temp = a;
      }
    }
    cout << ans << endl;
  }
  
}