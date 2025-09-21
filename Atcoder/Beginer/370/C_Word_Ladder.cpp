#include <bits/stdc++.h>
using namespace std;


int main(){
  string s,t;
  cin >> s >> t;

  vector<pair<char,int>> pp;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] != t[i]){
      pp.push_back({t[i],i});
    }
  }

  vector<string>ans;
  ans.push_back(s);
  for (int i = 0; i < pp.size(); i++)
  {
    auto[x,y] = pp[i];
    string temp;
    if(s[y] > t[y]){
      temp = ans[(int)ans.size() - 1];
      temp[y] = x;
      ans.push_back(temp);
    }
  }

  for (int i = pp.size() - 1; i >= 0; i--)
  {
    auto[x,y] = pp[i];
    string temp;
    int sz = (int)ans.size()-1;
    temp = ans[sz];
    if(temp[y] != t[y]){
      temp[y] = x;
      ans.push_back(temp);
    }
  }
  
  cout << ans.size()-1 << endl;
  int k = 0;
  for(auto x : ans){
    if(k == 0) k++;
    else cout << x << endl;
  }
}