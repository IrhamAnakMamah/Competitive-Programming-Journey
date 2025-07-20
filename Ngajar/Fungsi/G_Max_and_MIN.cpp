#include <iostream>
using namespace std;

int maks(int a,int b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}

int minim(int a,int b){
  if(a<b){
    return a;
  }else{
    return b;
  }
}

int main(){
  int n;
  int mx = 0;
  int mn = 100000; 
  cin >> n;
  // 1 2 3 4 5
  // 1 
  for(int i=0;i<n;i++)
  {
    int a;
    cin >> a;
    mx = maks(mx,a);
    mn = minim(mn,a);
    //mx = 10
    //mn = 10

    //mx = 13
    //mn = 10

    //mx = 95
    //mn = 10

    //...

    //mx = 95
    //mn = 1
  }
  cout << mn << " " << mx << endl;
}