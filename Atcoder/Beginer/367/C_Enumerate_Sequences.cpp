#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[8];

vector<vector<int>> ans;

void f(int index, int jumlah, vector<int> cache){
  if(n == index){
    if(jumlah % k == 0){
      ans.push_back(cache);
    }
  }

  for (int i = 1; i <= a[index]; i++)
  {
    cache.push_back(i);
    f(index+1, jumlah + i, cache);
    cache.pop_back();
  }
  
}

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 1; i <= a[0]; i++)
  {
    vector<int> cache;
    cache.push_back(i);
    f(1,i,cache);
  }
  
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
}