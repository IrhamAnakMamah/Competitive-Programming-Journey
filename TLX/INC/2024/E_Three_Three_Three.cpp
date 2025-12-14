#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;

    int sz = (int)s.length();
    int ans = 0;

    vector<int> cache;

    for (int i = 0; i < sz; i++)
    {
      cache.push_back(s[i] - '0');
      while (cache.size() >= 3)
      {
        int k = cache.size();
        if((cache[k-1] + cache[k-2] + cache[k-3]) % 3 == 0){
          ans++;
          cache.erase(cache.end() - 2);
        }else{
          break;
        }
      }
      
    }
    
    cout << (ans&1 ? "Anda" : "Kamu") << endl;
  }
  
}