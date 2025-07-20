#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  set<int> d;
  d.insert(1);
  for (int i = 2; i <= sqrt(c); i++)
  {
    int temp = c;
    if(temp%i==0){
      d.insert(i);
      while(temp%i==0){
        temp/=i;
        d.insert(temp);
      }
    }
  }
  d.insert(c);
  int cnt = 0;
  cout << d.size() << endl;
}