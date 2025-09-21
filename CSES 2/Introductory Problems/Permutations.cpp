#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  if(n<=3 && n!=1){
    cout << "NO SOLUTION" << endl;
  }else if(n == 4){
    cout << "2 4 1 3" << endl;
  }else{
    int a = 1;
    int b = (n+1)/2 + 1;

    for (int i = 0; i < n; i++)
    {
      if(i&1){
        cout << b << " ";
        b++;
      }else{
        cout << a << " ";
        a++;
      }
    }
    cout << endl;
    
  }
}