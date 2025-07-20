#include <iostream>
#include <string>
using namespace std;

void permute(string s, string hasil = "") {
    if (s.empty()) {
        cout << hasil << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        string sisa = s.substr(0, i) + s.substr(i + 1);
        permute(sisa, hasil + s[i]);
    }
}

int main() {
    string input = "ABC";
    permute(input);
    return 0;
}
