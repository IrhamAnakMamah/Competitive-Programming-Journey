#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,m,count1 = 0, ans = 0;
    string s;
    char c;
    cin >> n >> m >> c;
    vector<pair<string,bool>> a;

    for (int i = 0; i < n; i++)
    {
      cin >> s;
      if(s[0]>'A'){

      }else{
        
      }
      a.push_back(make_pair(s,true));
    }
    for (int i = 0; i < m; i++)
    {
      cin >> s;
      for (int i = 0; i < n; i++)
      {
        if(s[1] == a[i].first[1]){
          
        }
      }
      
    }
    
  }
  
}