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
    string s;
    cin >> s;
    int q;
    cin >> q;
    int leng = (int)s.length();
    if(leng<4){
      for (int i = 0; i < q; i++)
      {
        int x,y;
        cin >> x >> y;
        cout << "NO" << "\n";
      }
    }else{
      int sum = 0;  
      for (int i = 0; i < leng - 3; i++)
      {
        if(s.substr(i,4)=="1100") sum++;
      }
      
      for (int i = 0; i < q; i++)
      {
        int index;
        char x;
        cin >> index >> x;
        index--;
        for (int i = max(index-3,0); i <= min(leng-4,index); i++)
        {
          if(s.substr(i,4)=="1100")sum--;
        }
        s[index] = x;
        if(index>=3){
          for (int i = index-3; i <= min(leng-4,index); i++)
          {
            if(s.substr(i,4)=="1100")sum++;
          }
        }else{
          for (int i = 0; i <= min(leng-4,index); i++)
          {
            if(s.substr(i,4)=="1100")sum++;
          }
        }
        cout << (sum ? "YES" : "NO") << "\n";
      }
      
    }
  }
  
}