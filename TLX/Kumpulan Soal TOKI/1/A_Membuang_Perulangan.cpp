#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<int,bool> cek;
  vector<int>ans;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    if(!cek.count(x)){
      ans.push_back(x);
      cek[x] = 1;
    }
  }

  for(auto x : ans){
    cout << x << endl;
  }
}