#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s,t;
    cin >> s >> t;
    int temp = max(s.length(),t.length());
    if(t.length() == temp){
      string z = t;
      t = s;
      s = z;
    }
    
    int ans = 0;
    bool cek = 1;
    for (int i = 0; i < temp; i++)
    {
      if(i>=t.length()){
        ans+=s.length()-t.length();
        break;
      }else if(s[i]==t[i] && cek){
        int x = 0;
        for (int j = i; j < t.length(); j++)
        {
          if(s[j]==t[j])x++;
          else break;
        }
        i+=(x-1);
        x++;
        ans+=x;
      }else{
        cek = 0;
        ans+=2;
      }
    }
    cout << ans << '\n';
  }
  
  
}