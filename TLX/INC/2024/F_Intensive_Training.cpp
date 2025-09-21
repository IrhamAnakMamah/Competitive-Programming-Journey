#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    ll n,m,k;
    cin >> n >> m >> k;

    ll hariAtas = m%n;
    ll hariBawah = n - hariAtas;

    ll nilaiAtas = k%n;
    ll nilaiBawah = n - nilaiAtas;

    ll a = (m+hariBawah)/n; // hari atas
    ll b = m/n; // hari bawah

    ll c = (k+nilaiBawah)/n; // nilai atas
    ll d = k/n; // nilai bawah

    if(hariAtas == 0 && nilaiAtas == 0){
      cout << (b * d) * n << endl;
    }else if(hariAtas == nilaiBawah){
      cout << (a * d) * hariAtas + (b * c) * hariBawah << endl;
    }else if(nilaiAtas > hariBawah){
      ll temp = nilaiAtas - hariBawah;
      cout << (c * b) * hariBawah + (c * a) * temp + (d * a) * nilaiBawah << endl;
    }else{
      ll temp = hariBawah - nilaiAtas;
      cout << (c * b) * nilaiAtas + (b * d) * temp + (d * a) * hariAtas << endl;
    }
  }
  
}