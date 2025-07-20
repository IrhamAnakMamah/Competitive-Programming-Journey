#include <bits/stdc++.h>
#include <array>
using namespace std;
#define ll long long
#define pb push_back
#define debug cout<<"BUG"<<endl


int main ()
{
    string a = "AOYEUIaoyeui";
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        bool ok = 1;
        for (int j = 0; j < a.length(); j++)
        {
            if(s[i]==a[j]){
                ok=0;
                break;
            }
        }
        if(ok==0){
            continue;
        }else{
            s[i] = tolower(s[i]);
            cout << "." << s[i];
        }
    }
    
    return 0;
}