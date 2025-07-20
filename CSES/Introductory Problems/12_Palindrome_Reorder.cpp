#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  string ans;
  cin >> s;
  if(s.length()<3) {
    cout << s << endl;
    return 0;
  }
  vector<int> a(26, 0);
  for(int i = 0; i < s.length(); i++) {
    int n = s[i]-'A';
    a[n]++;
  }
  bool ok = 1;
  int count = 0;
  for(int i = 0;i<26;i++) {
    if((a[i]%2==1) && a[i]!=0) count++;
  }
  if(count>1) ok=0;
  if(ok) {
    string temp;
    for(int i=0;i<26;i++) {
      if((a[i]&1) && a[i]!=0){
        temp = string(a[i], 'A'+i);
      }else if((a[i]%2==0) && a[i]!=0) {
        int n = a[i]/2;
        string t = string(n, 'A'+i);
        ans+=t;
      }
    }
    ans+=temp;
    for(int i = 25; i>=0;i--) {
      if((a[i]%2==0) && a[i]!=0) {
        int n = a[i]/2;
        string t = string(n, 'A'+i);
        ans+=t;
      }
    }
    cout << ans << endl;
  }else{
    cout << "NO SOLUTION" << endl;
  }
}