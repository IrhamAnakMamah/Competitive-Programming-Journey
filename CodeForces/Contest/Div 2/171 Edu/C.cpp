#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    ll ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int j = s.length();
    for(int i = 1 ; i<=s.length();i++){
      if(s[i-1]=='1'){
        int temp = j-1;
        while (true)
        {
          if(s[temp]=='0'){
            j--;
            break;
          }else{
            j--;
          }
        }
        ans+=temp;
      }
    }
  }
  
}