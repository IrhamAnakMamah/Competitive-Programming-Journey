#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if(n==2){
      cout << 2 << "\n";
      cout << 1 << " " << 2 << "\n";
    }else{
      cout << 2 << '\n';
      for (int i = n; i > 1; i--)
      {
        cout << n << " " << i-1 << "\n";
        if((n+(i-1))%2==1){
          n = ((n+(i-1))/2)+1;
        }else{
          n = (n+(i-1))/2;
        }
      }
      
    }
  }
  
}