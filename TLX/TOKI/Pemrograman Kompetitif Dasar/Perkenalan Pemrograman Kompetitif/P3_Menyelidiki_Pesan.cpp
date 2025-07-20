#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string a,b,c;
  cin >> a >> b >> c;

  vector<pair<char,char>> code;

  bool ok = 1;
  int j = 0;

  for (int i = 0; i < n; i++)
  {
    for(auto z : code){
      if(z.first == a[i]){
        if(z.second != b[i]){
          ok = 0;
          break;
        }
      }
    }
    code.push_back({a[i],b[i]});
  }
  
  unordered_map<char,char> ans;

  for(auto z : code){
    ans[z.second] = z.first;
  }

  string wow = "";
  bool no = 0;
  
  for (int i = 0; i < n; i++)
  {
    auto temp = ans.find(c[i]);
    if(temp!=ans.end()){
      wow += temp->second;
    }else{
      wow += '?';
    }
  }
  cout << wow << "\n";
  
}