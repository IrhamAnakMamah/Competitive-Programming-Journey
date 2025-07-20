#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if(n&1){
      if(n<27){
        cout << -1 << endl;
      }else{
        cout << "1 2 2 3 3 4 4 5 5 1 6 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 6 ";
        for (int i = 14; i <= n/2; i++)
        {
          cout << i << " " << i << " ";
        }
        cout << endl;
      }
    }else{
      for (int i = 1; i <= n/2; i++)
      {
        cout << i << " " << i << " ";
      }
      cout << endl;
    }
  }
  
}