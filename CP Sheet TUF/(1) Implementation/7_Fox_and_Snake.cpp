#include <bits/stdc++.h>
using namespace std;

int main (){
  int n,m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    if(i%2==0){
      if(i%4==0){
        cout << "#";
        for (int i = 0; i < m-1; i++)
        {
          cout << ".";
        }
        cout << "\n";
      }else{
        for (int i = 0; i < m-1; i++)
        {
          cout << ".";
        }
        cout << "#" << "\n";
      }
    }else{
      for (int i = 0; i < m; i++)
      {
        cout << "#";
      }
      cout << "\n";
    }
  }
  
}