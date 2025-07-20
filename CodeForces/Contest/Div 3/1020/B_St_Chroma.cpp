#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int x;
    cin >> x;

    int mx = n-1;

    for (int i = 0; i < n; i++)
    {
      if(i>=x){
        cout << mx << " ";
        mx--;
      }else{
        cout << i << " ";
      }
    }
    cout << endl;
  }
  
}
