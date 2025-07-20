#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;

  // 2 3 5

  if((n<7) && (n == 2 || n == 3 || n == 5)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}