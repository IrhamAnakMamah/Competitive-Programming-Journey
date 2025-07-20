#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> a;
  for (int i = 0; i < n; i++)
  {
    int x,y;
    cin >> x >> y;
    a.push_back({x,y});
  }
  

  sort(a.begin(),a.end());

  for (int i = 0; i < n-1; i++)
  {
    if(a[i].second > a[i+1].second){
      cout << "Happy Alex\n"; 
      return 0;
    }
  }
  
  cout << "Poor Alex\n";
  
}