#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int sum = 0;
    while(c!=d){
      if(c==a || c==b){
        sum++;
      }
      c++;
      if(c==13){
        c=1;
      }
    }
    cout << (sum==0 || sum==2 ? "NO" : "YES") << endl;
  }
  
}