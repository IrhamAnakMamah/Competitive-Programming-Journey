/*
Author : Irham
Date : 6 October 2024
Problem : Three Pairwise Maximums
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
  int t;
  cin >> t;
  while (t--)
  {
    int a,b,c,count = 0;
    cin >> a >> b >> c;
    if(a==c && a==b && b==c){
      cout << "YES\n";
      cout << a << " " << a << " " << a << '\n';
    }else if(a==b && c<a){
      cout << "YES\n";
      cout << a << " " << c << " 1\n";
    }else if(a==c && b<a){
      cout << "YES\n";
      cout << a << " " << b << " 1\n";
    }else if(b==c && a<b){
      cout << "YES\n";
      cout << a << " 1 " << b << "\n"; 
    }else{
      cout << "NO" << "\n";
    }
  }
  
}