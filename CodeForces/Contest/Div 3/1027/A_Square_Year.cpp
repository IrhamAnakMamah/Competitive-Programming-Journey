#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    for (int i = 0; i < 100; i++)
    {
      if(i*i==n){
        cout << 0 << " " << i << endl;
        break;
      }else if(i==99){
        cout << -1 << endl;
      }
    }
    

  }
  
  
}