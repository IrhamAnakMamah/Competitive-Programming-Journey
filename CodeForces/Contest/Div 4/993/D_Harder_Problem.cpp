#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n+1,0), b(n+1,0);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      if(a[x]==0){
        b[i] = x;
        a[x] = 1;
      }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
      if(a[i]==0){
        q.push(i);
      }
    }
    for (int i = 0; i < n; i++)
    {
      if(b[i]==0){
        b[i] = q.front();
        q.pop();
      }
    }
    for (int i = 0; i < n; i++)
    {
      cout << b[i] << " ";
    }
    cout << endl;
  }
  
}