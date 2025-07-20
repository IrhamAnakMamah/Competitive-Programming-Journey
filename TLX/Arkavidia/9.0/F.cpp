#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,a,b;
  cin >> n >> a >> b;

  string arka,vidia;
  cin >> arka >> vidia;

  int nyawa_pohon = INT_MAX;
  int index_akhir = -1;
  int nyawa_final = 0;

  int arr[n];

  //# = 3 * b
  //. = nyawa / 2

  for (int i = 0; i < n; i++)
  {
    nyawa_final += b;
    if(arka[i]==vidia[i]){
      if(arka[i]=='#'){
        nyawa_final -= 3*b;
      }else{
        nyawa_final/=2;
      }
    }
    arr[i] = nyawa_final;
    if(nyawa_final<nyawa_pohon){
      nyawa_pohon = nyawa_final;
      index_akhir = i;
    }
    
  }

  //kasus 1 jika nilai nyawa pohon < 0, bakal cek pada bagian 
  for (int i = 0; i < n; i++)
  {
    if(nyawa_pohon > 0){
      if(arka[i] == vidia[i]){
        cout << -1 << " ";
      }else{
        if()
      }
    }else{
      if(arka[i] == vidia[i]){
        int temp = arr[i]/2;
        int tolak = max(nyawa_pohon, nyawa_final);
        if(temp + tolak > 0){
          
        }
      }else{

      }
    }
  }
  
}