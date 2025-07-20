#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n-1; i++)
  {
    int temp = a[i];
    cout << temp << " ";
    for (int j = i+1; j < n-1; j++)
    {
      temp+=a[j];
      cout << temp << " ";
    }
    cout << endl;
  }
  
  
}