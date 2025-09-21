#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  stack<char> st;
  bool ok = 1;
  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];
    if(c == '(' || c == '[' || c == '<'){
      st.push(c);
    }else{
      bool cek = 0;
      char x;
      if(st.empty()){
        cek = 1;
      }else{
        x = st.top();
        st.pop();
        if(c == ')' && x != '(') cek = 1;
        if(c == ']' && x != '[') cek = 1;
        if(c == '>' && x != '<') cek = 1;
      }
      
      if(cek){
        ok = 0;
      }
    }
  }
  if(!st.empty()){
    ok = 0;
  }
  cout << (ok ? "Yes" : "No") << endl;
}