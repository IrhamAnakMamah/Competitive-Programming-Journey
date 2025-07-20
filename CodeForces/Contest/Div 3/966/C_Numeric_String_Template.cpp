#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    cin >> q;
    for (int i = 0; i < q; i++)
    {
      string s;
      cin >> s;
      if(s.length()==n){
        bool ok = 0;
        map<int,char> cache1;
        map<char,int> cache2;
        for (int i = 0; i < n; i++)
        {
          char c = s[i];
          int temp = a[i];
          if(cache1.count(temp)==0 && cache2.count(c)==0){
            cache1[temp]=c;
            cache2[c]=temp;
          }else if(cache1[temp]!=c || cache2[c]!=temp){
            ok = 1;
          }
        }
        cout << (ok ? "NO" : "YES") << "\n";
      }else{
        cout << "NO" << "\n";
      }
    }
    
  }
  
}