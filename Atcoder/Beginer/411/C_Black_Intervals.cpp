#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> kotak(n+1,0);

  int total = 0;
  for (int i = 0; i < q; i++)
  {
    int a;
    cin >> a;
    if(kotak[a] == 1){
      if(kotak[a-1] == 1 && kotak[a+1] == 1){
        total++;
      }else if((kotak[a+1] == 1 && a == 1) || (kotak[a-1] == 1 && a == n)){
      }else if(kotak[a-1] == 1 || kotak[a+1] == 1){

      }else{
        total--;
      }
      kotak[a] = 0;
    }else{
      if(kotak[a-1] == 1 && kotak[a+1] == 1){
        total--;
      }else if((kotak[a+1] == 1 && a == 1) || (kotak[a-1] == 1 && a == n)){
      }else if(kotak[a-1] == 1 || kotak[a+1] == 1){

      }else{
        total++;
      }
      kotak[a] = 1;
    }
    cout << total << endl;
  }
  
}