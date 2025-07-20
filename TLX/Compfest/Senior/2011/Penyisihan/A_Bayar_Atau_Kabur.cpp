#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,c,d;
    string s;
    cin >> a >> b >> c >> d >> s;

    int temp = a*b*c;
    if(s == "bayar"){
      cout << d - temp << endl;
    }else{
      cout << -1 * temp << endl;
    }
  }
  
}