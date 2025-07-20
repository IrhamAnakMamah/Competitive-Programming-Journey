#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int mn = 1000000000;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if(a[i]<mn){
      mn = a[i];
    }
  }
  
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if(a[i]==mn){
      count++;
    }
  }
  if(count%2==1){
    cout << "Lucky" << endl;
  }else{
    cout << "Unlucky" << endl;
  }
}