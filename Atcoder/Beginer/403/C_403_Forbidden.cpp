#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m,q;
  cin >> n >> m >> q;

  vector<bool> all(n+1, 0);
  map<pair<int,int>, int> mp;
  for (int i = 0; i < q; i++)
  {
    int a;
    cin >> a;
    if(a == 1){
      int b,c;
      cin >> b >> c;
      mp[{b,c}] = 1;
    }else if(a == 2){
      int b;
      cin >> b;
      all[b] = 1;
    }else{
      int b,c;
      cin >> b >> c;
      if(all[b]){
        cout << "Yes" << endl;
      }else if(mp.find({b,c}) != mp.end()){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl; 
      }
    }
  }
  
}