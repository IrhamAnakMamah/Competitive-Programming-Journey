#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = 1;
    int satutemp = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i]=='1'){
        satutemp++;
      }else{
        satutemp = 0;
      }
      if(satutemp==2) ok = 0;
    }
    if(s[0]=='1' || s[n-1]=='1' || !ok){
      cout << "YES"  << "\n";
    }else{
      cout << "NO" << "\n";
    }
  }
  
}