#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  double ans = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] != 't') continue;
    for (int j = i+2; j < s.length(); j++)
    {
      if(s[j] != 't') continue;

      double jumlah = 0;
      for (int k = i; k <= j; k++)
      {
        if(s[k] == 't')jumlah++;
      }
      
      double temp = (jumlah - 2)/(j-i+1-2);
      ans = max(temp,ans);
    }
    
  }

  cout << fixed << setprecision(17) << ans << endl;
}