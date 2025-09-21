#include <bits/stdc++.h>
using namespace std;

int n,k,x;
vector<string> s;
vector<string> ans;

int test = 0;

void f(int jumlah, string t){
  if(jumlah == k){
    ans.push_back(t);
  }else{
    for (int i = 0; i < n; i++)
    {
      f(jumlah + 1, t + s[i]);
    }
  }

}

int main(){
  cin >> n >> k >> x;

  for (int i = 0; i < n; i++)
  {
    string t;
    cin >> t;
    s.push_back(t);
  }
  
  f(0,"");
  
  sort(ans.begin(), ans.end());
  // for(auto t : ans){
  //   cout << t << endl;
  // }

  cout << ans[x-1] << endl;
}