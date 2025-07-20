#include <iostream>
using namespace std;

const int MAXN = 1000000 + 5;
bool a[MAXN];

int Fungsi(int index)
{
  if(index<0){
    index = abs(index)+1000;
  }
  if(a[index]==false){
    a[index] = true;
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int n,jawaban = 0;
  cin >> n;
  for (int i = 0; i < MAXN; i++)
  {
    a[i] = false;
  }
  
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    int temp = Fungsi(x);
    jawaban+=temp;
  }
  cout << jawaban << endl;
}