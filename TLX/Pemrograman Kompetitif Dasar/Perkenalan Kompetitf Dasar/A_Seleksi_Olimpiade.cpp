#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct a
{
  string id;
  int x1,x2,x3;
};

bool ok(a b, a c){
  if(b.x3 > c.x3) return true;
  else if (b.x3 < c.x3) return false;
  if(b.x2 > c.x2) return true;
  else if (b.x2 < c.x2) return false;
  if(b.x1 > c.x1) return true;
  else return false;
}

void solve (){
  int n,m;
  string target;
  cin >> n >> m;
  cin >> target;
  a peserta[n];
  for (int i = 0; i < n; i++)
  {
    cin >> peserta[i].id >> peserta[i].x1 >> peserta[i].x2  >> peserta[i].x3;
  }
  sort(peserta, peserta + n, ok);

  for (int i = 0; i < m; i++)
  {
    if(target == peserta[i].id){
      cout << "YA" << endl;
      return;
    }
  }
  cout << "TIDAK" << endl;
}

int main (){
  int n;
  cin >> n;
  while (n--)
  {
    solve();
  }
  
}