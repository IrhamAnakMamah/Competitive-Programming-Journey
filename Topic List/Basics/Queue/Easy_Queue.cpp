#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  scanf("%d", &t);
  queue<int> a;
  while (t--)
  {
    int n,m;
    scanf("%d", &n);
    if(n == 1){
      scanf("%d", &m);
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