#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    string n;
    int j,k;
    cin >> n >> j >> k;
    j--;
    k--;
    vector<string> ans;

    do
    {
      ans.push_back(n);
    } while (next_permutation(n.begin(), n.end()));
    
    sort(ans.begin(), ans.end());
    vector<int> cache(10, 0);
    for (int i = 0; i < n.size(); i++)
    {
      cache[ans[j][i]-'0']++;
    }
    
    int a = 0;
    int b = 0;
    for (int i = 0; i < n.size(); i++)
    {
      if(ans[j][i] == ans[k][i]){
        a++;
        cache[ans[j][i]-'0']--;
      }else if(cache[ans[j][i]-'0'] != 0){
        cache[ans[j][i]-'0']--;
        b++;
      }
    }
    cout << a << "A" << b << "B" << endl;
  }
  
}