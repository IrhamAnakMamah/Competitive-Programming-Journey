#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,a,b;
    cin >> n >> a >> b;
    string s = "";
    string temp = "";
    for (int i = 0; i < b; i++)
    {
      temp+='a'+i;
    }
    int op = b-1;
    for (int i = b; i < a; i++)
    {
      temp+='a'+op;
    }
    for (int i = 0; i < n/a; i++)
    {
      s+=temp;
    }
    s += temp.substr(0,(n%a));
    cout << s << endl;
  }
  
}