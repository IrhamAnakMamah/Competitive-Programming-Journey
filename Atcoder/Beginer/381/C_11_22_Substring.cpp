#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if(s[i]=='/'){
      int j = 1;
      int temp = 1;
      while (true)
      {
        if(i-j>=0 && i+j<n){
          if(s[i-j]=='1' && s[i+j]=='2'){
            temp+=2;
            j++;
          }else{
            break;
          }
        }else{
          break;
        }
      }
      ans = max(ans,temp);
    }
  }
  cout << ans << "\n";
}