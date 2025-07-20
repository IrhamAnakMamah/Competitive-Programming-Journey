#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int n,k;
vector<bool> ada(MAXN, 0);

int f(int a[], int i, vector<int>& cache){
  if(n == i){
    return 0;
  }

  int masuk1 = 0;
  int skip1 = 0;
  int plus = 0;
  int final = 0;

  // kalo mau diskip
  skip1 = f(a,i+1,cache);

  if(ada[a[i]]){
    // jika elemen sekarang sama dengan yang ada pada box
    plus = 1 + f(a,i+1,cache);
  }else{
    // jika masih ada yang kosong
    if(cache.size() < k){
      cache.push_back(a[i]);
      ada[a[i]] = 1;
      masuk1 = f(a,i+1,cache);
    }else{
      //jika sudah penuh dan ingin diisi kembali
      int temp = 0;
      int temp1 = 0;
      for (int j = 0; j < k; j++)
      {
        temp = cache[j];
        ada[temp] = 0;
        ada[a[i]] = 1;
        cache[j] = a[i];
        temp1 = f(a,i+1,cache);
        ada[temp] = 1;
        ada[a[i]] = 0;
        cache[j] = temp;
        final = max(temp1, final);
      } 
    }
  }

  cout << i << endl;
  cout << masuk1 << " " << skip1 << " " << plus << " " << final << endl << endl;

  return max({masuk1,skip1,plus,final});
}

int main(){
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  vector<int> cache;
  int ans = f(a,0,cache);
  cout << ans << endl;
}