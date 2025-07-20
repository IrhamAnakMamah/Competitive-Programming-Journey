#include <iostream>
using namespace std;
// link : https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/C

int main(){
  int n;
  cin >> n;
  int genap = 0;
  int ganjil = 0;
  int positif = 0;
  int negatif = 0;

  int a;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if(a>0){
      positif++;
    }else if(a<0){
      negatif++;
    }

    a = abs(a);
    
    if(a%2==1){
      ganjil++;
    }else if(a%2==0){
      genap++;
    }

  }
  cout << "Even: " << genap << endl;
  cout << "Odd: " << ganjil << endl;
  cout << "Positive: " << positif << endl;
  cout << "Negative: " << negatif << endl;
}