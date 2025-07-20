#include <bits/stdc++.h>
using namespace std;

int main (){
    int a,b;
    cin >> a >> b;
    int ans = 0;
    int x = a;
    int y = b;
    for (int i = 1; i < 100; i++)
    {
        x = x*3*i;
        y = y*2*i;
        ans++;
        if(x>y) break;
    }
    cout << ans << endl;
}