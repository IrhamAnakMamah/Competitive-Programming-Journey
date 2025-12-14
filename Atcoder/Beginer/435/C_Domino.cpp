#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n+1];
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  
  priority_queue<int> pq;
  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    if(i == 1){
      pq.push(i + a[i] - 1);
      ans++;
    }else if(pq.top() >= i){
      pq.push(i + a[i] - 1);
      ans++;
    }else{
      break;
    }
    
  }
  cout << ans << endl;
}