#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
  return a.second < b.second;
}

int main(){
  int n;
  cin >> n;

  vector<pair<int,int>> p; // first dan second

  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    p.push_back({x,y});
  }
  
  sort(p.rbegin(), p.rend(), comp);

  for(auto [x,y] : p){
    cout << "First : " << x << ", Second : " << y << endl;
  }
}