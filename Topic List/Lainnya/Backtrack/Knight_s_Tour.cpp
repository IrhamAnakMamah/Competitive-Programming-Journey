#include <bits/stdc++.h>
using namespace std;

// x kiri kanan
// y atas bawah
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};

vector<vector<bool>> vis(8, vector<bool>(8, 0));
vector<vector<int>> ans;
vector<vector<int>> rekam(8, vector<int>(8, 0));
bool ok = 0;
int hitung = 1;

// kalo count = (8^2 - 1), maka simpan di ans

bool cek(int x, int y){
  return x >= 0 && x < 8 && y >= 0 && y < 8;  
}

void cari(int a, int b){
  if(hitung == 64){
    ans = rekam;
    ok = 1;
  }else{
    for (int i = 0; i < 8; i++)
    {
      int x = dx[i] + a;
      int y = dy[i] + b;
      if(cek(x,y)){
        if(!vis[x][y]){
          vis[x][y] = 1;
          hitung++;
          rekam[x][y] = hitung;
          cari(x,y);
          vis[x][y] = 0;
          rekam[x][y] = 0;
          hitung--;
        }
      }
    }
    
  }
}

int main(){
  int x,y;
  cin >> x >> y;
  x--;
  y--;
  vis[x][y] = 1;
  rekam[x][y] = 1;
  cari(x,y);
  cout << hitung << endl;
}