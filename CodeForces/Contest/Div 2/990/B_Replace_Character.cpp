#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if(j==i){
          continue;
        }else{
          string temp = s;
          temp[i] = s[j];
          int sum = 0;
          int mxt = 0;
          for (int k = 0; k < n; k++)
          {
            if(k==0){
              sum++;
            }else if(temp[k]==temp[k-1]){
              sum++;
            }else{
              mxt = max(mxt,sum);
              if(mxt > mx){
                mx = mxt;
                ans = temp;
              }
              sum = 1;
            }
          }
          if(sum != 1){
            mxt = max(mxt,sum);
            if(mxt > mx){
              mx = mxt;
              ans = temp;
            }
          }
        }
      }
      
    }
    if(ans.length() == 0){
      ans = s;
    }
    cout << ans << endl;
  }
  
}