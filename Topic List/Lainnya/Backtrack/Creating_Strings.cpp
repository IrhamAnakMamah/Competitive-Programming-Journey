#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ans;
string temp;
vector<bool> cek(9, 0);

void search(){
  if(temp.length() == s.length()){
    ans.insert(temp);
  }else{
    for (int i = 0; i < s.length(); i++)
    {
      if(cek[i]) continue;
      cek[i] = 1;
      temp.push_back(s[i]);
      search();
      cek[i] = 0;
      temp.pop_back();
    }
    
  }
}

int main(){
  cin >> s;

  search();
  cout << ans.size() << endl;
  for(auto x : ans){
    cout << x << endl;
  }
}