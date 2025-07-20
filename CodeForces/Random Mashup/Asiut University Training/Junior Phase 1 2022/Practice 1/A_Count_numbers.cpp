#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n >> q;
    int a[n+1];
    for (int i = 0; i <= n+1; i++)
    {
      a[i] = 0;
    }
    
    for (int i = 0; i < q; i++)
    {
      int z,x;
      cin >> z >> x;
      if(z==1){
        a[x]++;
      }else{
        cout << a[x] << endl;
      }
    }
    
  }
  
}