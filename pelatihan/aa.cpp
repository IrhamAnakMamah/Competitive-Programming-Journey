#include<iostream>
using namespace std; 

int main()
{
  int a,b; 
  char op; 
  cin >> a >> op >> b; 

  if(op=='+')
  {
    cout << a+b << endl;
  } 
  if(op=='-')
  {
    cout << a-b << endl;
  }
  if(op=='*')
  {
    cout << a*b << endl;
  }
  if(op=='>')
  {
    if(a>b)
    {
      cout << "benar" << endl;
    }
    else 
    {
      cout << "salah" << endl;
    }
  }
  if(op=='<')
  {
    if(a<b)
    {
      cout << "benar" << endl;
    }
    else 
    {
      cout << "salah" << endl;
    }
  }
  if(op=='=')
  {
    if(a==b)
    {
      cout << "benar" << endl;
    }
    else 
    {
      cout << "salah" << endl;
    }
  } 

}