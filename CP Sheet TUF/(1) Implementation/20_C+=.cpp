#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    long long a,b,n,i = 1;
    cin >> a >> b >> n;
    while(true)
    {
      if(b>a){
        a+=b;
        i++;
      }else{
        b+=a;
        i++;
      }

      if(a>n || b>n){
        break;
      }
    }
    cout << i-1 << '\n';
  }
  
}