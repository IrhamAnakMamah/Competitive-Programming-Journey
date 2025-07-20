#include <iostream>
using namespace std;

void Fungsi(int n, char c)
{
  for(int i=0;i<n;i++)
  {
    cout << c << " ";
  }
  cout << endl;
}

int main(){
  int t; 
  cin >> t; 
  int n;
  char c;
  for(int i=0;i<t;i++)
  {
    cin >> n; 
    cin >> c; 
    Fungsi(n,c);
  }
}