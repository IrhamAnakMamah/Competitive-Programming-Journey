#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  bool ok = (s[0] == 'B' ? 0 : 1);
  vector<int> A,B;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'A'){
      A.push_back(i);
    }else{
      B.push_back(i);
    }
  }
  
  cout << endl;
  int ans = 0;
  // kalo ok, huruf pertama A
  int i = 0, j = 0;

  while (i < n && j < n)
  {
    if(A[i] % 2 == 0){
      i++;
      continue;
    }
    if(B[j]&1){
      j++;
      continue;
    }
    ans += abs(A[i] - B[j]);
    i++;
    j++;
  }
  
  int ans2 = 0;
  i = 0, j = 0;
  while (i < n && j < n)
  {
    if(B[i] % 2 == 0){
      i++;
      continue;
    }
    if(A[j]&1){
      j++;
      continue;
    }
    ans2 += abs(B[i] - A[j]);
    i++;
    j++;
  }

  ans = min(ans,ans2);
  cout << ans << endl;
}