#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> arr;
vector<int> vis;

bool f(vector<int> &nums, vector<int> a){
  if(nums.size() == a.size()){
    arr.push_back(nums);
  }else{
    for (int i = 0; i < a.size(); i++)
    {
      if(!vis[i]){
        nums.push_back(a[i]);
        vis[i] = 1;
        f(nums, a);
        vis[i] = 0;
        nums.pop_back();
      }
    }
  }
}

int main(){
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vis.resize(n+1, 0);
  sort(a.begin(), a.end());
  vector<int> nums;
  f(nums, a);
  for(auto x : arr){
    for(auto y : x){
      cout << y << " ";
    }
    cout << endl;
  } 
}