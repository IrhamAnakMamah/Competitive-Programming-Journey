#include <bits/stdc++.h>
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int n,count = 0;
    int a[101];
    cin >> n;
    for (int i = 5; i >= 0; i--)
    {
      int power = pow(10,i);
      if(n/power!=0){
        int temp = n/(power);
        a[count] = temp*(power);
        n = n%(power);
        count++;
      }
    }
    cout << count << "\n";
    for (int i = 0; i < count; i++)
    {
      cout << a[i] << " ";
    }
    cout << "\n";
  }
  
}