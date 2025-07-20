#include <bits/stdc++.h>
using namespace std;

/*

  tujuannya yaitu untuk mengetahui string server atau pc[0]. untuk penyelesaiannya bersifat terbalik, dengan kata lain melakukan iterasi dari q sampai 1. jadi mengetahui asal usul terlebih dahulu.

*/

int main(){
  int n,q;
  cin >> n >> q;

  int x[q],y[q];
  vector<string> b(q);

  for (int i = 0; i < q; i++)
  {
    cin >> x[i] >> y[i];
    if(x[i] == 2){
      cin >> b[i];
      reverse(b[i].begin(),b[i].end());
    }
  }
  string ans;
  // point bertujuan untuk melacak, sesuai namanya.
  int point = 0;
  for (int i = q-1; i >= 0; i--)
  {
    // jika x[i] = 1, yang dimana pc = server, maka dicek apakah point sama dengan y[i]. dengan kata lain si point ini sama dengan pc yang ditunjuk? jika iya, maka point dirubah jadi 0
    if(x[i] == 1){
      if(point == y[i]){
        point = 0;
      }
    //jika x[i] = 2, yang dimana pc += string, maka dicek apakah point yang sekarang sama dengan y[i]. jika iya, maka ans ditambah string.
    }else if(x[i] == 2){
      if(point == y[i]){
        ans += b[i];
      }
    //jika x[i] = 3, yang dimana server = pc, maka dicek apakah point sama dengan 0. jika iya, maka point dirubah menjadi y[i].
    }else{
      if(point == 0){
        point = y[i];
      }
    }
  }
  // kalo sudah, dibalik jawabannya
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}