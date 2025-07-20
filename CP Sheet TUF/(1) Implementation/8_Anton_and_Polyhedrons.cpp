#include <bits/stdc++.h>
using namespace std;

int main (){
  int t,ans = 0;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    if(s == "Tetrahedron"){
      ans+=4;
    }else if(s == "Cube"){
      ans+=6;
    }else if(s == "Octahedron"){
      ans+=8;
    }else if(s == "Dodecahedron"){
      ans+=12;
    }else if(s == "Icosahedron"){
      ans+=20;
    }
  }
  cout << ans << "\n";
}