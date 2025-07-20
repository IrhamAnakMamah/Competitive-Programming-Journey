#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> a,pair<string,int> b){
  if(a.second == b.second){
    return a.first < b.first;
  }else{
    return a.second > b.second;
  }
}

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<string,int>> a;
    for (int i = 0; i < n; i++)
    {
      string s;
      int x;
      cin >> s >> x;
      a.push_back({s,x});
    }
    sort(a.begin(),a.end(),comp);

    for(auto b : a){
      auto [x,y] = b;
      cout << x << " " << y << endl;
    }
  }
  
}