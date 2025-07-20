#include <iostream>
#include <vector>
using namespace std;

int main (){
  int n,m,k;
  cin >> n >> m >> k;

  vector<int> a(n+1), s(n+1), high(m+1, -1);
  vector<vector<int>> langsung(k+1, vector<int>(0));

  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> s[i];
    high[s[i]] = max(high[s[i]], a[i]);
  }
  int b;
  for (int i = 1; i <= k; i++)
  {
    cin >> b;
    langsung[i].push_back(a[b]);
    langsung[i].push_back(s[b]);
  }
  
  int jumlah = m + k;

  for (int i = 1; i <= k; i++)
  {
    if(langsung[i][0] == high[langsung[i][1]]){
      jumlah--;
    }
  }
  cout << jumlah << '\n';

}