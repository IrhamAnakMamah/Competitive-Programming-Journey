#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  char a[n];
  int b[n];

  int total = 0;
  bool ok = 1;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i];
    total+=b[i];
    if(total > 100){
      ok = 0;
    }
  }

  if(!ok){
    cout << "Too Long" << endl;
  }else{
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < b[i]; j++)
      {
        cout << a[i];
      }
      
    }
    cout << endl;
  }
}