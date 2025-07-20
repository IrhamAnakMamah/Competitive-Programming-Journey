#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

//ide awalnya yaitu menggunakan map, karena graf disini tidak terhubung secara langsung dan kompleksitas memorinya (10^9), maka dari itu menggunakan map. jadi disini keynya menandakan titik kordinat dan setelah menandakan jumlah atau tanda, berupa int dan bool.

//untuk belok
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, 1, -1};

int main(){
  int x0,x1,y0,y1;
  cin >> x0 >> y0 >> x1 >> y1;

  int n;
  cin >> n;

  //dist untuk ngitung jarak, boleh untuk tanda diperbolehkan lewat sana, vis menandakan apakah sudah pernah berkunjung atau ngga
  map<pair<int,int>, int> dist;
  map<pair<int,int>, bool> boleh;
  map<pair<int,int>, bool> vis;
  
  int r,a,b;
  for (int i = 0; i < n; i++)
  {
    cin >> r >> a >> b;
    for (int j = a; j <= b; j++)
    {
      boleh[{r,j}] = 1;
    }
    
  }
  
  auto bfs = [&] (int a, int b){
    dist[{a,b}] = 0;
    queue<pair<int,int>> q;
    q.emplace(a,b);
    while (!q.empty())
    {
      auto[c,d] = q.front();
      q.pop();

      for (int i = 0; i < 8; i++)
      {
        int x = c + dx[i];
        int y = d + dy[i];

        //pertama bakal ngecek apakah udah pernah berkunjung atau ngga dan juga ngecek apakah diperbolehkan atau ngga, untuk yang lainnya dicek apakah nilai dist kosong atau nilai dist hasil belok lebih besar dari dist awal (c,d) + 1
        if((boleh[{x,y}] && !vis[{x,y}]) && (!dist[{x,y}] || dist[{x,y}] > dist[{c,d}] + 1)){
          dist[{x,y}] = dist[{c,d}] + 1;
          q.emplace(x,y);
        }
      }
      //menandakan udah pernah berkunjung
      vis[{c,d}] = 1;
    }
    
  };

  bfs(x0,y0);

  //jika sampai pada tujuan, maka keluarkan hasilnya
  if(vis[{x1,y1}]){
    cout << dist[{x1,y1}] << endl;
  }else {
    cout << -1 << endl;
  }
}

