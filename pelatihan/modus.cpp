#include <bits/stdc++.h>
using namespace std;

int main(){
  int banyak[100000];
  for (int i = 0; i < 100000; i++)
  {
    banyak[i] = 0;
  }
  
  int n;
  int max = 0;
  int bilangan = 0;
  cin >> n;
  int a[n];
  

  for(int i = 0; i<n; i++){
    cin >> a[i];
    banyak[a[i]-1]++;
  }

  for (int i = 0; i < 100000; i++)
  {
    if(max<=banyak[i]){
      max = banyak[i];
      bilangan = i+1;
    }
  }
  cout << bilangan << endl;
}