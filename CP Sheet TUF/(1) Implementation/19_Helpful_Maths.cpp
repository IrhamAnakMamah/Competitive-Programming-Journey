#include <bits/stdc++.h>
using namespace std;

int main (){
    string s;
    cin >> s;
    string copy;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]!='+'){
            copy += s[i];
        }
    }
    sort(copy.begin(), copy.end());
    cout << copy[0];
    for (int i = 1; i < copy.length(); i++)
    {
        cout << "+" << copy[i];
    }
}