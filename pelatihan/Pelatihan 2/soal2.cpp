#include <iostream>
using namespace std;

int main(){
  int n;
  int a,b;
  cin >> n;

  for (int i = 1; i <= 100; i++)
  {
    for (int j = 1; j <= 100; j++)
    {
      if(i*j==n){
        a = i;
        b = j;
      }
    }
  }
  cout << a << " " << b << endl;
}