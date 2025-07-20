#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int bawah = (((n+1)/2)-1)-1;
  int tengah = (((n+1)/2))-1;
  bool ok = 1;
  if(n%2==0) ok = 0;
  for (int i = 0; i < n; i++)
  {
    if((s[i]=='1' && i<=bawah) || (s[i]=='/' && i==tengah) || (s[i]=='2' && i>tengah)){

    }else{
      ok = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl; 
}