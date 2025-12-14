#include <bits/stdc++.h>
using namespace std;

int sum[101];
int ans[101];

void precomp(){
  sum[0] = 1;
  sum[1] = 1;
  ans[0] = 1;
  ans[1] = 1;

  for (int i = 2; i < 101; i++)
  {
    ans[i] = ans[i-1] + sum[i-1];
    string temp = to_string(ans[i]);
    for (int j = 0; j < temp.length(); j++)
    {
      sum[i] += (temp[j] - '0');
    }
  }
  
}

int main(){
  precomp();
  int n;
  cin >> n;
  cout << ans[n] << endl;
}