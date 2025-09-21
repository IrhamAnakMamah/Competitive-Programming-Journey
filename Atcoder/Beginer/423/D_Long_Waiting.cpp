#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<tuple<int,int,int>> a(n);
  for (int i = 0; i < n; i++)
  {
    int x,y,z;
    cin >> x >> y >> z;
    a[i] = {x,y,z};
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  int pesanan = 0;
  int waktu = 0;
  for (int i = 0; i < n; i++)
  {
    auto [x,y,z] = a[i];
    while (!pq.empty())
    {
      auto[a,b] = pq.top();
      if(a <= max(waktu, x)){
        pesanan-=b;
      }else{
        break;
      }
      pq.pop();
    }
    
    if(z + pesanan <= k){
      waktu = max(waktu, x);
      pq.push({waktu+y, z});
      pesanan += z;
    }else{
      while (!pq.empty() && pesanan + z > k)
      {
        auto[a,b] = pq.top();
        pesanan-=b;
        waktu = max(waktu, a);
        pq.pop();
      }
      pesanan += z;
      waktu = max(waktu, x);
      pq.push({waktu+y, z});
    }
    cout << waktu << endl;
  }
  
}