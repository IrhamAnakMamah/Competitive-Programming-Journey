#include <bits/stdc++.h>
using namespace std;


int n,k,m;

void f(vector<string> &ans, string s){
  if(s.length()==n){
    ans.push_back(s);
    return;
  }

  for (int i = 0; i < k; i++)
  {
    string temp;
    char c;
    c = 'a'+i;
    temp+=s;
    temp+=c;
    f(ans,temp);
  }
  
}

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = 0; i < k; i++)
    {
      char c = 'a'+i;
      string temp;
      temp = c;
      f(ans,temp);
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << endl;
    }
    
  }
  
}