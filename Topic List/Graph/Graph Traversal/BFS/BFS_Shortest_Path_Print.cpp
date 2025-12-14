/*

  Author  : Iham.
  Date    : 10.08.2024
  Tag     : BFS Shortest Path with Print

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

vector<int> bfs(int x, int y){
  vector<int> ans;
  int p[100001];
  p[x] = -1;

  queue<int> q;
  q.push(x);
  vis[x] = 1;

  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    vis[v] = 1;
    for(auto u : adj[v]){
      if(!vis[u]){
        q.push(u);
        p[u] = v;
      }
    }
  }
  
  for (int i = y; p[i] != -1; i = p[i])
  {
    ans.push_back(i);
  }
  ans.push_back(x);

  reverse(ans.begin(), ans.end());
  return ans;
}

int main(){
  int n; // Memasukkan Banyaknya Node
  cout << "Silahkan Masukkan Jumlah Node : ";
  cin >> n;

  int m; // Memasukkan Jumlah Penghubung Antar Node
  cout << "Silahkan Masukkan Banyaknya Penghubung Antar Node : ";
  cin >> m;

  cout << endl;
  
  adj.resize(n+1);
  for (int i = 0; i < m; i++)
  {
    int x,y; // Penghubung Antar Node X dan Y
    cout << "Penghubung " << i+1 << endl << endl;
    cout << "Node 1 : ";
    cin >> x;
    cout << "Node 2 : ";
    cin >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    cout << endl;
  }

  cout << endl;
  int q; // Memasukkan Query yang Akan Dilaksanakan
  cout << "Masukkan Banyaknya Query : ";
  cin >> q;
  cout << endl;
  
  for (int i = 0; i < q; i++)
  {
    vis.clear();
    vis.resize(n+1);
    int x, y; // Menanyakan Shortest Path antara Node X dan Node Y
    cout << "Silahkan Masukkan Node yang ingin diukur jarak terpendeknya : " << endl;
    cout << "Node 1 : ";
    cin >> x;
    cout << "Node 2 : ";
    cin >> y;

    
    vector<int> p = bfs(x, y);
    cout << endl;
    cout << "Jarak terpendek dari Node " << x << " ke Node " << y << " yaitu : " << p.size()-1 << endl;
    cout << "Dengan Rute : " << endl;
    for(auto a : p){
      cout << a << (p.back() == a ? "\n" : "->");
    }
    cout << endl;
  }
  
}