#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  queue<long long> a;
  while (t--)
  {
    long long n,m;
    cin >> n;
    if(n == 1){
      cin >> m;
      a.push(m);
    }else if(n==2){
      if(!a.empty()){
        a.pop();
      }
    }else{
      if(a.empty()){
        cout << "Empty!" << endl;
      }else{
        cout << a.front() << "\n";
      }
    }
  }
  
}