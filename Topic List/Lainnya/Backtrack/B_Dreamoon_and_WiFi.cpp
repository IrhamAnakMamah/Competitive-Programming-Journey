#include <bits/stdc++.h>
using namespace std;

string t;
int akhir1 = 0;

int cek(int x, int panjang){
  if(x == t.length()){
    if(panjang == akhir1){
      return 1;
    }else{
      return 0;
    }
  }

  int kanan = 0;
  int kiri = 0;
  if(t[x] == '?'){
    kanan += cek(x+1, panjang+1);
    kiri += cek(x+1, panjang-1);
  }else{
    if(t[x] == '+'){
      kanan += cek(x+1, panjang + 1);
    }else{
      kiri += cek(x+1, panjang - 1);
    }
  }

  return kanan + kiri;
}

int main(){
  string s;
  cin >> s;

  cin >> t;

  int count = 0;
  for (int i = 0; i < (int)s.length(); i++)
  {
    if(s[i] == '+'){
      akhir1++;
    }else{
      akhir1--;
    }

    if(t[i] == '?'){
      count++;
    }
  }
  
  int akhir2 = cek(0,0);
  cout << fixed << setprecision(12) << (double)((akhir2 * 1.0)/pow(2,count)) << endl;
}