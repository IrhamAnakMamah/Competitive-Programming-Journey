#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  vector<string> a(t, "Empty");

  int j = 0;
  int k = 0;
  for (int i = 0; i < t; i++)
  {
    string s,x;
    cin >> s;
    if(s == "Enqueue"){
      cin >> x;
      a[j] = x;
      j++;
    }else{
      cout << a[k] << "\n";
      if(a[k]=="Empty"){

      }else k++;
    }

  }
  
  
}