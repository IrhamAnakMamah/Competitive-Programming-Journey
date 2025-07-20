#include <iostream>
using namespace std;

int main (){
  int n,d;
  cin >> n >> d;
  int a[n];
  for(int i = 0; i<n;i++){
    cin >> a[i];
  }
  for(int i = 0;i<n;i++){
    if(a[i]==d){
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}