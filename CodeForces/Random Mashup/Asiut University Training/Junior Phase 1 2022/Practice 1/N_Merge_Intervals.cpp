#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for (int i = 0; i < n; i++)
    {
      int l,r;
      cin >> l >> r;
      a.push_back({l,r});
    }
    sort(a.begin(),a.end());
    int temp1 = 0;
    int temp2 = 0;
    for (int i = 0; i < n; i++)
    {
      auto [x,y] = a[i];
      if(temp1 == 0){
        temp1 = x;
        temp2 = y;
      }else if(x > temp2){
        cout << temp1 << " " << temp2 << endl;
        temp1 = x;
        temp2 = y;
      }else{
        temp2 = max(temp2,y);
      }
    }
    cout << temp1 << " " << temp2 << endl;
  }
  
}