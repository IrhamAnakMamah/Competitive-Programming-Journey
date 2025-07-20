#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  multiset<int> price;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    price.insert(a);
  }
  
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    auto temp = price.upper_bound(x);
    if(temp == price.begin()){
      cout << -1 << "\n";
    }else{
      temp--;
      cout << *(temp) << "\n";
      price.erase(temp);
    }
  }
  
}