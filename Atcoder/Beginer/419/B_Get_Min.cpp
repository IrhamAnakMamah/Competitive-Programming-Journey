#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  priority_queue<int, vector<int>,greater<int>> pq;
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if(a == 1){
      int x;
      cin >> x;
      pq.push(x);
    }else{
      cout << pq.top() << endl;
      pq.pop();
    }
  }
  
}