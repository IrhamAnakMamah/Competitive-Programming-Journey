#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m;
    cin >> n >> m;

    string s;
    cin >> s;

    map<int,int> mp;
    for (int i = 0; i < m; i++)
    {
      int a;
      cin >> a;
      mp[a]++;
    }

    int k = 2;
    while (true)
    {
      if(mp.find(k) == mp.end()){
        break;
      }
      k++;
    }
    
    int titik = 1;
    for (int i = 0; i < n; i++)
    {
      if(s[i] == 'A'){
        titik++;
        mp[titik]++;
        if(titik == k){
          while (true)
          {
            if(mp.find(k) == mp.end()){
              break;
            }
            k++;
          }
        }
      }else{
        titik = k;
        mp[titik]++;
        while (true)
        {
          if(mp.find(k) == mp.end()){
            break;
          }
          k++;
        }
        titik = k;

        k++;
        while (true)
        {
          if(mp.find(k) == mp.end()){
            break;
          }
          k++;
        }
        
      }
    }
    
    cout << mp.size() << endl;
    for(auto [x,y] : mp){
      cout << x << " ";
    }
    cout << endl;
  }
  
}