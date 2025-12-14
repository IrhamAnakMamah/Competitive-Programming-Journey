#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int a = 0,b = 0,c = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      if(x == -1){
        a++;
      }else if(x == 0){
        b++;
      }else{
        c++;
      }
    }
    
    if(a%2==0 && b==0 && c >= 1){
      cout << 0 << endl;
    }else{
      cout << (a%2)*2 + b << endl;
    }
  }
  
}