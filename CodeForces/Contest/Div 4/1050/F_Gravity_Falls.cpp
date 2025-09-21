#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    vector<int> ans;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
      int k;
      cin >> k;
      int ganti = 0;
      for (int j = 0; j < k; j++)
      {
        int a;
        cin >> a;
        if(i == 0){
          ans.push_back(a);
          len = k;
        }else{
          if(ans.size() < j+1){
            ans.push_back(a);
          }else if(ganti == 0){
            if(ans[j] < a){
              ganti = 2;
            }
            else if(ans[j] > a && ganti == 0){
              ganti = 1;
              ans[j] = a;
            }
          }else if(ganti == 1){
            ans[j] = a;
          }else if(ganti == 2){
            if(len <= j){
              if(ans[j] > a){
                ganti = 1;
                ans[j] = a;
              }
            }
          }
        }
      }
      if(len != 0){
        len = k;
      }
      if(ganti == 1){
        if(len > k){
          len = k;
        }
      } 
    }
    for(auto x : ans){
      cout << x << " ";
    }
    cout << endl;
  }
  
}