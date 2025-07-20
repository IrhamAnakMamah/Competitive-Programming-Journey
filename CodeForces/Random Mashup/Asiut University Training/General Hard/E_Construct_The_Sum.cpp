#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n,s;
    cin >> n >> s;
    vector<int > a;
    while(n>0 && s>0){
      if(n>s){
        n--;
        continue;
      }else{
        a.push_back(n);
        s-=n;
        n--;
      }
    }
    if(s!=0){
      cout << -1 << "\n";
    }else{
      reverse(a.begin(), a.end());
      cout << a.size() << " ";
      for(auto x : a){
        cout << x << " ";
      }
      cout << "\n";
    }
  }
  
}