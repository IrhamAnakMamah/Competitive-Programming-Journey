#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6 + 5;
ll cache[MAXN];

void Count(){
  //menghitung jumlah divisor disetiap elemen
  for (int i = 1; i < MAXN; i++)
  {
    for (int j = i; j < MAXN; j+=i)
    {
      cache[j]+=i;
    }
    
  }
  
}

int main(){
  Count();
  int n;
  cin >> n;
  while(n--){
    int a;
    cin >> a;
    cout << cache[a] - a<< "\n";
  }
}