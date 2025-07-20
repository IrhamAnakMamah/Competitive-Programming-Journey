#include <iostream>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n-i; j++)
      {
        int mx = 0;
        for (int k = j; k <= j+i; k++)
        {
          if(mx<a[k]){
            mx = a[k];
          }
        }
        cout << mx << ' ';
      }
      
    }
    cout << endl;
  }
  
}