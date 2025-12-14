#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s,t;
  cin >> s >> t;

  vector<int> v1, v2; // butuh 1 dan butuh 0
  for (int i = 0; i < n; i++)
  {
    if(s[i] != t[i]){
      if(s[i] == '0'){
        v1.push_back(i+1);
      }else{
        v2.push_back(i+1);
      }
    }
  }
  
  int ans = 0;
  int i = 0;
  int j = 0;
  while (i < v1.size() && j < v2.size())
  {
    if(abs(v1[i] - v2[j]) == 1){
      ans+=abs(v1[i] - v2[j]);
      i++;
      j++;
    }else{
      ans++;
      if(v1[i] > v2[j]){
        j++;
      }else{
        i++;
      }
    }
  }
  
  while (i < v1.size())
  {
    ans++;
    i++;
  }
  
  while (j < v2.size())
  {
    ans++;
    j++;
  }
  cout << ans << endl;
}