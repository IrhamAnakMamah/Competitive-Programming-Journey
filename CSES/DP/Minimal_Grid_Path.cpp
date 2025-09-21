#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s[n];
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }
  
  vector<string> dp2(n+1, "");
  
  for (int i = 0; i < n; i++)
  {
    vector<string> dp1(n+1);
    for (int j = 0; j < n; j++)
    {
      // kondisi dimana dp2 kosong
      if(i == 0){
        if(j == 0){
          dp1[0] = s[0][0];
        }
        if(j > 0){
          dp1[j] = dp1[j-1] + s[i][j];
        }
      }else{
        if(j == 0){
          dp1[j] = dp2[j] + s[i][j];
        }else{
          dp1[j] = min(dp1[j-1], dp2[j]);
          dp1[j] = dp1[j] + s[i][j];
        }
      }
    }
    dp2 = dp1;
  }
  

  cout << dp2[n-1] << endl;
}