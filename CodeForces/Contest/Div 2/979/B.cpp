#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >>n;
    if(n==1){
      cout << 0;
    }else if (n==2){
      cout << "01";
    }else{
      string s = string (n,'0');
      if(n&1){
        s[n/2] = '1';
      }else{
        s[(n/2)-1] = '1';
      }
      cout << s;
    }
    cout << "\n";
  }
  
}