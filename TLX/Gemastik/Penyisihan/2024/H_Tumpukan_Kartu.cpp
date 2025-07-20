#include <bits/stdc++.h>
using namespace std;

struct node{
  int info;
  node* kanan;
  node* kiri;
};

node *awal, *akhir, *bantu, *nb;

void buatlist(){
  awal = NULL;
  akhir = NULL;
}

bool listkosong(){
  return (awal == NULL);
}

void sisipnode(int n){
  nb = new node;
  nb->info = n;
  nb->kiri = NULL;
  nb->kanan = NULL;

  if(listkosong()){
    awal = nb;
    akhir = nb;
  } else{ 
    nb->kanan = awal;
    awal->kiri = nb;
    awal = nb;
  }
}

void gantinode(node *a){

  // cout << (a != awal) << endl;
  if(a != awal){
    // cout << a->info << endl;
    bantu = a->kiri;
    a->kiri->kanan = NULL;
    akhir->kanan = awal;
    a->kiri = NULL;
    awal->kiri = akhir;
    awal = a;
    akhir = bantu;
  }

}

int main(){
  buatlist();
  unordered_map<int,node *> cek;

  int n,q;
  cin >> n >> q;

  int jumlah = n;
  
  int a[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = n-1; i >= 0; i--)
  {
    sisipnode(a[i]);
    cek[a[i]] = awal;
  }
  

  for (int i = 0; i < q; i++)
  {
    char c;
    cin >> c;
    int x;
    cin >> x;
    
    if(c == 'A'){
      jumlah++;
      sisipnode(x);
      cek[x] = awal;
    }else{
      gantinode(cek[x]);
    }
  }

  cout << jumlah << endl;
  
  for(bantu = awal; bantu != NULL; bantu = bantu->kanan){
    cout << bantu->info << " ";
  }
  cout << endl;
  
}