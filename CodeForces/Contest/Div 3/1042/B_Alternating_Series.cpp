#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      if(i == n-1 && i&1){
        cout << 2 << endl;
      }else{
        cout << (i&1 ? 3 : -1) << (i+1 == n ? "\n" : " ");
      }
    }
    
  }
  
}