#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int satu = 0;
    int count = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      if(s[i] == '1'){
        count++;
        satu++;
      }else{
        mx = max(count, mx);
        count = 0;
      }
    }
    mx = max(count , mx);
    if(mx >= k){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
      int uhuy = 1;
      satu++;
      for (int i = 0; i < n; i++)
      {
        if(s[i] == '0'){
          cout << satu << " ";
          satu++;
        }else{
          cout << uhuy << " ";
          uhuy++;
        }
      }
      cout << endl;
    }
  }
  

}