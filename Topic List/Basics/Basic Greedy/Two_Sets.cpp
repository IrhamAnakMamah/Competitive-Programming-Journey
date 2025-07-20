#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int > a,b;
  int sum1 = 0;
  int sum2 = 0;
  bool ok = 1;
  for (int i = 0; i < n; i++)
  {
    if(n-i==n){
      a.push_back(n);
      sum1 +=n;
      ok = 0;
    }else if(!ok){
      sum2+=n-i;
      b.push_back(n-i);
    }else{
      sum1+=n-i;
      a.push_back(n-i);
    }
    if(i%2==0 && i!=0){
      ok^=1;
    }
  }
  if(sum1 == sum2){
    cout << "YES\n";
    cout << a.size() << "\n";
    for(auto x : a){
      cout << x << " ";
    }
    cout << "\n";
    cout << b.size() << "\n";
    for(auto x : b){
      cout << x << " ";
    }
    cout << "\n";
  }else{
    cout << "NO\n";
  }
}