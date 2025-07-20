#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  cin >> n;
  while (n--)
  {
    int a,b;
    cin >> a >> b;
    if(a>=b){
      cout << a << '\n';
    }else{
      if(a*2>b){
        cout << a-(b-a) << '\n';
      }else{
        cout << 0 << '\n';
      }
    }
  }
  
}