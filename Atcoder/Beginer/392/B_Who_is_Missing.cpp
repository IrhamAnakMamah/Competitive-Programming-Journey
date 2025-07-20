#include <bits/stdc++.h>
using namespace std;

int main(){
  int t = 1;
  // cin >> t;
  while (t--)
  { 
    int n,m;
    cin >> n >> m;
    int a[m+1];
    for (int i = 1; i <= m; i++)
    {
      cin >> a[i];
    }
    sort(a+1,a+m+1);
    vector<int> b;
    int k = 1;
    for (int i = 1; i <= n; i++)
    {
      if(a[k]!=i){
        b.push_back(i);
      }else{
        k++;
      }
    }
    cout << b.size() << endl;
    if(b.size()>0){
      for(auto x : b){
        cout << x << " ";
      }
      cout << endl;
    }
  }
  
}