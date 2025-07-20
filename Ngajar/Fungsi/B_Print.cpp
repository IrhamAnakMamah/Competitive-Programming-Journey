#include <iostream>
using namespace std;

void Fungsi(int n)
{
  for(int i=1;i<n;i++) // 1 2 3 4
  {
    cout << i << " ";
  }
  cout << n << endl;
}

int main(){
  int n; 
  cin >> n; 
  Fungsi(n);  
}