#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  bool ok = 1;

  int ans = 0;
  ans++;
  for (int i = 0; i < s.length() - 1; i++)
  {
    int temp = s[i] - '0';
    int temp2 = s[i+1] - '0';
    if(i==0){
      if(temp > temp2){
        ans++;
        ans+=temp;
      }else{
        ans++;
        ans+=(10-temp2)+temp2;
      }
    }else{
      int j = 0;
      int count = 0;
      for (j = i+1; j < s.length(); j++)
      {
        if(temp2 == s[j]-'0'){
          count++;
        }else{
          break;
        }
      }
      ans+=count;
      cout << i << " " << j << endl << endl;
      i = j - 2;
      if(temp > temp2){
        ans+=(10-temp)+temp2;
      }else{
        ans+=(10-temp2)+temp2;
      }
    }
  }
  if(s.length() == 1){
    ans = s[s.length()-1] - '0';
  }
  cout << ans << endl;
}