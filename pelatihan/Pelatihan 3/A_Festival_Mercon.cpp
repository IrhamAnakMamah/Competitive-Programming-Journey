#include <iostream>
using namespace std;

int ganjil(int a[], int n){
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if(a[i]%2==1){
      count++;
    }
  }
  
  if(count%2==1){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  int n;
  int ans = 0;
  cin >> n;

  int a[n];
  int b[n];

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  
  ans = ganjil(a,n);
  cout << ans << endl;
}