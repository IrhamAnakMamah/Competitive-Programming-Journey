#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    int cnt = 0;
    int mn = a[0];
    for (int i = 1; i < n; i++)
    {
      if(mn < a[i]){
        cnt++;
        if(!s.empty()){
          if(s.top() < a[i]){
            while(!s.empty() && s.top() < a[i]){
              mn = s.top();
              cnt++;
              s.pop();
            }
            if(!s.empty()){
              mn = a[i]; 
            }
          }
        }
      }else{
        s.push(mn);
        mn = a[i];
      }
    }
    cout << (cnt == n-1 ? "YES" : "NO") << endl;
  }
  
}