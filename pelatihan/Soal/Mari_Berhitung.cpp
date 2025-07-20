#include <iostream>
using namespace std;

int main(){
  int n,o,p;
  int ans = 0;
  cin >> n >> o >> p;
  
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  ans=a[0];

  for (int i = 1; i < n; i++)
  {
    if(o==1){
      ans+=a[i];
    }else{
      ans-=a[i];
    }
  }
  cout << (ans==p ? "Benar" : "Salah") << endl;
  
}