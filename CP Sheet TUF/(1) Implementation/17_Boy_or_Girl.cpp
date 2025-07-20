#include <bits/stdc++.h>
using namespace std;

int main (){
      string s;
    cin >> s;
    int a[27];
    memset(a, 0, sizeof(a));
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i]-'a']++;
        if(a[s[i]-'a']>1){
            continue;
        }else sum++;
    }
    (sum%2==0) ? cout << "CHAT WITH HER!" << endl : cout << "IGNORE HIM!" << endl;
}