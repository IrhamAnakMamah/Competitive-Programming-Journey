#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,m;
  cin >> n >> m;
  set<pair<int,int>> place;
  vector<pair<int,int>> move{{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
  for (int i = 0; i < m; i++)
  {
    ll x,y;
    cin >> x >> y;
    place.insert({x,y});
    for(auto [dx,dy] : move){
      if(1 <= x+dx && x+dx<=n && 1 <= y+dy && y+dy <=n){
        place.insert({x+dx,y+dy});
      }
    }
  }
  cout << (n*n) - place.size() << endl;
}