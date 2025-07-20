#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++)
    {
      ans.push_back({b[i],b[a[i]-1]});
    }
    sort(ans.begin(),ans.end());
    for(auto z : ans){
      auto[x,y] = z;
      cout << y << " ";
    }
    cout << endl;
  }
  
}