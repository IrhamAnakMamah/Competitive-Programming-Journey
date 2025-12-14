#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<vector<int>> cache(n, vector<int>(n, -1));

  int k = 1;
  int x = 0; // r
  int y = (n-1)/2; // c
  cache[x][y] = k;
  k++;
  // ((r−1)modN,(c+1)modN)
  for (int i = 0; i < (n * n - 1); i++)
  {
    int temp1 = ((x-1) + n) % n;
    int temp2 = (y+1) % n;
    if(cache[temp1][temp2] == -1){
      cache[temp1][temp2] = k;
      x = temp1;
      y = temp2;
    }else{
      cache[(x+1) % n][y] = k;
      x = (x+1) % n;
    }
    k++;
  }
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << cache[i][j] << " ";
    }
    cout << endl;
  }
  
}