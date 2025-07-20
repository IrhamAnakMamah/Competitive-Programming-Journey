#include <bits/stdc++.h>
using namespace std;

int n,k;
const int MAXN = 1e5+5;
int a[MAXN];

int batasatas(int x){
  int l = -1;
  int r = n;
  while(l+1<r){
    int sum = (l+r)/2;
    if(a[sum]>x) r = sum;
    else l = sum;
  }
  return r;
}

int batasbawah(int x){
  int l = -1;
  int r = n;
  while(l+1<r){
    int sum = (l+r)/2;
    if(a[sum]<x) l = sum;
    else r = sum;
  }
  return l;
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  sort(a,a+n);
  cin >> k;
  while (k--)
  {
    int l,r;
    cin >> l >> r;
    int bawah = (batasbawah(l));
    int atas = (batasatas(r));
    cout << atas - bawah - 1 << " ";
  }
  cout << "\n";
}