#include <iostream>
using namespace std;

int penjumlahan(int x, int y)
{
  return x+y;
}

int main(){
  int x,y;
  cin >> x >> y; 
  int hasil; 
  hasil = penjumlahan(x,y); 
  cout << hasil << endl;
}