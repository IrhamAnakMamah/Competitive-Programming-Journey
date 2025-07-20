#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string temp = "aiueo";
    int n;
    cin >> n;
    string ans = "";
    if(n<=5){
      cout << temp.substr(0,n) << endl;
    }else{
      int x = n%5;
      ans+=string(n/5+(x>=1),'a') + string(n/5+(x>=2),'e') + string(n/5 + (x>=3),'i') + string(n/5 + (x>=4),'o') + string(n/5,'u');
      cout << ans << "\n";
    }
  }
  
}