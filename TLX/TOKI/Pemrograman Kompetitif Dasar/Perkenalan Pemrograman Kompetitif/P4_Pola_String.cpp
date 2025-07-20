#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int k = 1;
  int panjang = 1;
  while(panjang<s.length()){
    k++;
    panjang = k*k;
  }

  bool ok = 1;
  bool cek = 0;
  int j = k-1;

  for (int i = 0; i < panjang; i++)
  {
    if(ok){
      if(i >= s.length()){
        cout << ".";
      }else{
        cout << s[i];
      }
    }else{
      if(i+k > s.length() && !cek){
        int x = k-(abs((i - (int)s.length()))%k);
        if(i>s.length()) x = k;
        for (int j = 0; j < x; j++)
        {
          cout << ".";
        }
        if(x==k) i = (i-1)+k;
        cek = 1;
      }else{ 
        if(j-(i%k) >= s.length())continue;
        cout << s[j - (i%k)];
        cek = 1;
      }
    }

    if((i+1)%k==0){
      ok^=1;
      cek = 0;
      j += k;
      cout << '\n';
    }
  }
  
}