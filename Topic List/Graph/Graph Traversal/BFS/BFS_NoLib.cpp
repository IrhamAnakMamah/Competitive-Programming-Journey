#include <iostream>
using namespace std;

template <typename T>
struct queue
{
  struct node
  {
    T info;
    node *next;
  };

  node *nb, *depan, *belakang, *hapus, *cur;
  
  queue(){
    depan = NULL;
    belakang = NULL;
  }

  bool empty()
  {
    return (depan == NULL);
  }

  void push(T info_baru)
  {
    nb = new node();
    nb->info = info_baru;

    nb->next = NULL;
    if (depan == NULL)
    {
      depan = nb;
    }
    else
    {
      belakang->next = nb;
    }
    belakang = nb;
  }

  void pop()
  {
    if (!empty())
    {
      hapus = depan;
      depan = depan->next;
      free(hapus);
    }
  }

  void Display()
  {
    if (!empty())
    {
      for (cur = depan; cur != NULL; cur = cur->next)
      {
        cout << cur->info << " ";
      }
    }
  }

  T front(){
    return depan->info;
  }
};

bool vis[10001];
queue<int> adj[10001];

void bfs(int x){
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  cout << x << " ";
  
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (adj[v].cur = adj[v].depan; adj[v].cur != NULL; adj[v].cur = adj[v].cur->next)
    {
      if(!vis[adj[v].cur->info]){
        q.push(adj[v].cur->info);
        cout << adj[v].cur->info << " ";
        vis[adj[v].cur->info] = 1;
      }
    }
  }
  
}

int main()
{
  int n;
  cin >> n;

  int m;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    int x,y;
    cin >> x >> y;
    adj[x].push(y);
    adj[y].push(x);
  }

  for (int i = 0; i < 10001; i++)
  {
    vis[i] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    if(!vis[i]){
      bfs(i);
      cout << endl;
    }
  }
}