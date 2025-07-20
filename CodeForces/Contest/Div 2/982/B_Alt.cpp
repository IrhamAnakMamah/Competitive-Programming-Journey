#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int cek = a[0];
    vector<int> temp;
    temp.push_back(cek);
    for (int i = 1; i < n; i++)
    {
      if(cek<=a[i]){
        cek = a[i];
        temp.push_back(cek);
      }
    }

    map<int,int> cache;
    for(auto x : temp){
      cache[x]++;
    }

    int mx = 0;
    for(auto x : cache){
      mx = max(mx,x.second);
    }

    cout << temp.size()-mx << endl;
    
  }
  
}