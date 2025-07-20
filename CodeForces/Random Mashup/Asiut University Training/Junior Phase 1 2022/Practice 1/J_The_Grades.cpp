#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,pair<string,int>> a, pair<int,pair<string,int>> b){
  if(a.first == b.first){
    return a.second.first < b.second.first;
  }else{
    return a.first > b.first;
  }
}

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<pair<int,pair<string,int>>> a;
    vector<int> nilai[n];
    for (int i = 0; i < n; i++)
    {
      string s;
      cin >> s;
      int sum = 0;
      for (int j = 0; j < 4; j++)
      {
        int x;
        cin >> x;
        sum+=x;
        nilai[i].push_back(x);
      }
      a.push_back({sum,{s,i}});
    }
    sort(a.begin(),a.end(), comp);
    for(auto b : a){
      // x, y, z
      auto [x,c] = b;
      auto [y,z] = c; 
      cout << y << " " << x << " ";
      for(auto nil : nilai[z]){
        cout << nil << " ";
      }
      cout << endl;
    }
  }
  
}