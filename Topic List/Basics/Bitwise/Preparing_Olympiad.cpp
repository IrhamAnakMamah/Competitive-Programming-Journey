#include <bits/stdc++.h>
using namespace std;

int n,l,r,x;
int a[16];

int f(int jumlah, int i, int maxim, int minim, int problem){
  if(i==n){
    if((jumlah>=l && jumlah<=r) && maxim-minim >= x && problem >=2){
      return 1;
    }else{
      return 0;
    }
  }

  int wow = 0;
  if(jumlah > r){
    return 0;
  }

  int temp1 = 0;
  int temp2 = 0;

  //kalo ngga diambil
  int notpick = f(jumlah,i+1,maxim,minim,problem);

  //kalo diambil
  minim = min(minim,a[i]);
  maxim = max(maxim,a[i]);
  int pick = f(jumlah+a[i],i+1,maxim,minim,problem+1);

  return pick+notpick;
}

int main(){
  cin >> n >> l >> r >> x;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = f(0,0,0,INT_MAX, 0);
  
  cout << ans << "\n";
}