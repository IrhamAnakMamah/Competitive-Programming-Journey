#include <bits/stdc++.h>
using namespace std;

void check (string t){
  string copy = t;
  string rev = t;
  reverse(rev.begin(), rev.end());
  if(copy==rev) cout << copy << " ";
  else return;
}

int main (){
  string s;
  int k = 0;
  vector<string> temp;
  getline(cin,s);
  for (int i = 0; i < s.length(); i++){
    if(s[i]==' '){
      temp.push_back(s.substr(i-k,k));
      k=0;
    }else{
      k++;
    }
    if(i==s.length()-1){
      temp.push_back(s.substr(i-k+1,k));
    }
  }
  for(int i = 0; i<temp.size();i++){
    string t = temp[i];
    check(t);
  }
  cout << "\n";
  return 0;
}