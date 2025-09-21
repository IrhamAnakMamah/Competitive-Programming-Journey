#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<int,int>> ans;

void hanoi(int n, int from, int to, int bantu){
  if(n == 1){
    ans.push_back({from,to});
  }else{
    hanoi(n-1, from, bantu, to);
    ans.push_back({from,to});
    hanoi(n-1, bantu, to, from);
  }

}

int main(){
  cin >> n;

  hanoi(n,1,3,2);
  cout << ans.size() << endl;

  for(auto [x,y] : ans){
    cout << x << " " << y << endl;
  }
}