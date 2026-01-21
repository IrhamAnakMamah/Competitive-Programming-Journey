#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<pair<int,int>> horses;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    horses.push_back({x, i+1});
  }
  
  sort(horses.begin(), horses.end());
  for (int i = 0; i < 3; i++)
  {
    cout << horses[i].second << " ";
  }
  cout << endl;
  
}